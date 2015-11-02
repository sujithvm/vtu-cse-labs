if {$argc != 1} {
	error "usage: p6.tcl <no. of nodes>"
	exit 0
}

set val(chan)		Channel/WirelessChannel
set val(prop)		Propagation/TwoRayGround		
set val(ant)		Antenna/OmniAntenna
set val(ll)		LL
set val(ifq)		Queue/DropTail/PriQueue
set val(ifqlen)		50
set val(netif)		Phy/WirelessPhy
set val(mac)		Mac/802_11
set val(rp)		AODV
set val(stop)		100
set opt(x)		750
set opt(y)		750
set val(nn)		[lindex $argv 0]

set ns [ new Simulator ]
set tr [ open p6.tr w ]
set nm [ open p6.nam w ]

$ns trace-all $tr
$ns namtrace-all-wireless $nm $opt(x) $opt(y)

#create topography object
set topo [new Topography]
$topo load_flatgrid $opt(x) $opt(y)

#create the GOD object
set god [create-god $val(nn)]

$ns node-config -adhocRouting	$val(rp) \
		-llType		$val(ll) \
		-macType	$val(mac) \
		-ifqType	$val(ifq) \
		-ifqLen		$val(ifqlen) \
		-antType	$val(ant) \
		-propType	$val(prop) \
		-phyType	$val(netif) \
		-topoInstance	$topo \
		-channelType	$val(chan) \
		-agentTrace	ON \
		-routerTrace	ON \
		-macTrace	OFF \
		-movementTrace	OFF

#create the nodes
for {set i 0} {$i < $val(nn)} {incr i} {
	set n($i) [$ns node]
	$n($i) random-motion 1
}

#initial positioning of mobile nodes in the topography
for {set i 0} {$i < $val(nn)} {incr i} {
	set xx [expr rand() * $opt(x)]
	set yy [expr rand() * $opt(y)]
	$n($i) set X_ $xx
	$n($i) set Y_ $yy
}

#specify the size of the nodes
for {set i 0} {$i < $val(nn)} {incr i} {
	$ns initial_node_pos $n($i) 40
}

#create a tcp agent and attach to node1
set tcp0 [ new Agent/TCP ]
$ns attach-agent $n(1) $tcp0

set ftp [ new Application/FTP ]
$ftp attach-agent $tcp0

set sink0 [ new Agent/TCPSink ]
$ns attach-agent $n(4) $sink0

$ns connect $tcp0 $sink0

proc finish {} {
	global ns nm tr
	$ns flush-trace
	close $tr
	close $nm
	exec nam p6.nam &
	exit 0
}

#produce some node movements
proc nodeMovementsRandom {} {
	global ns val opt n
	set now [$ns now]
	set timeInterval 5.0
	for {set i 0} {$i < $val(nn)} {incr i} {
		set xx [expr rand() * $opt(x)]
		set yy [expr rand() * $opt(y)]
		$ns at [expr $now + $timeInterval] "$n($i) setdest $xx $yy 20.0"
	}
	$ns at [expr $now + $timeInterval] "nodeMovementsRandom"
}

#create random source and destination
set src [expr int(rand()) * $val(nn)]
set des [expr int(rand()) * $val(nn)]

$n($src) color "Orange"
$n($des) color "Blue"

$ns at 0.0 "nodeMovementsRandom"
$ns at 5.0 "$ftp start"
$ns at 90.0 "$ftp stop"

for {set i 0} {$i < $val(nn)} {incr i} {
	$ns at $val(nn) "$n($i) reset"
}

$ns at $val(stop) "finish"
$ns run
