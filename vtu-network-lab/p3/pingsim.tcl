#create simulation event
set ns [new Simulator]

#enabling tracing
set tr [open ping.tr w]
set nf [open ping.nam w]

#record the events to the trace and animation files
$ns trace-all $tr
$ns namtrace-all $nf

#define the finish proc
proc finish {} {
	global ns nf tr
	close $tr
	close $nf
	exec nam ping.nam &
	exit 0
}

#create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2.5Mb 20ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n3 $n5 2Mb 10ms DropTail

set ping0 [new Agent/Ping]
set ping1 [new Agent/Ping]
set ping4 [new Agent/Ping]
set ping5 [new Agent/Ping]

$ns attach-agent $n0 $ping0
$ns attach-agent $n1 $ping1
$ns attach-agent $n4 $ping4
$ns attach-agent $n5 $ping5

$ns connect $ping0 $ping5
$ns connect $ping1 $ping4
$ns connect $ping4 $ping0
$ns connect $ping5 $ping1

#extra
$ns color 1 "Red"
$ns color 2 "Green"
$ns color 3 "Blue"
$ns color 4 "Yellow"

proc sendPingPacket {} {
	set pingInterval 0.01
	global ns ping0 ping1 ping4 ping5
	set now [ $ns now ]
	$ns at [expr $now + $pingInterval ] "$ping0 send"
	$ns at [expr $now + $pingInterval ] "$ping1 send"
	$ns at [expr $now + $pingInterval ] "$ping4 send"
	$ns at [expr $now + $pingInterval ] "$ping5 send"
	$ns at [expr $now + $pingInterval ] "sendPingPacket"
}
set seq 1
Agent/Ping instproc recv {from rtt} {
	global seq
	$self instvar node_
	puts "64 bytes from [$node_ id] icmp_req = $seq ttl = 64 time = $rtt ms"
	set seq [expr $seq+1]
}

$ping0 set class_ 1
$ping1 set class_ 2
$ping4 set class_ 3
$ping5 set class_ 4

$ns at 0.01 "sendPingPacket"

$ns rtmodel-at 3.0 down $n2 $n3
$ns rtmodel-at 5.0 up $n2 $n3

$ns at 10.0 "finish"

$ns run	




