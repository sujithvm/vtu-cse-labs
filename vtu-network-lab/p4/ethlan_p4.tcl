#create simulation event
set ns [ new Simulator ]

set tr [ open eth.tr w ]
set nf [ open eth.nam w ]

$ns trace-all $tr
$ns namtrace-all $nf

proc finish {} {
	global ns nf tr
	$ns flush-trace
	close $tr
	close $nf
	exec nam eth.nam &
	exit 0
}
$ns color 1 "Red"
$ns color 2 "Green"

set nNodes 10
for {set i 0} {$i < $nNodes} {incr i} {
	set n($i) [$ns node]
}

$ns make-lan "$n(0) $n(1) $n(2) $n(3) $n(4)" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n(5) $n(6) $n(7) $n(8) $n(9)" 10Mb 10ms LL Queue/DropTail Mac/802_3

Mac/802_3 set DataRate_ 10Mb

$n(4) color "Blue"
$n(5) color "Blue"

$ns duplex-link $n(4) $n(5) 10Mb 30ms DropTail
$ns queue-limit $n(4) $n(5) 10

set tcp [ new Agent/TCP ]
$ns attach-agent $n(0) $tcp

set ftp [ new Application/FTP ]
$ftp attach-agent $tcp

#set the file size in packets
#$ftp0 set maxPkts _1000

set sink [ new Agent/TCPSink ]
$ns attach-agent $n(9) $sink

$ns connect $tcp $sink

set udp [ new Agent/UDP ]
$ns attach-agent $n(3) $udp

set cbr [ new Application/Traffic/CBR ]
$cbr attach-agent $udp

set null [ new Agent/Null ]
$ns attach-agent $n(6) $null

$ns connect $udp $null

$cbr set interval_ 0.002
$cbr set packetsize_ 500

$ftp set packetsize_ 500

$tcp set class_ 1
$udp set class_ 2

set err [new ErrorModel]
$ns lossmodel $err $n(4) $n(5)

#change this to get required values
$err set rate_ 0.6

$ns at 2.0 "$cbr start"
$ns at 2.0 "$ftp start"
$ns at 18.0 "$ftp stop"
$ns at 18.0 "$cbr stop"

$ns at 20.0 "finish"

$ns run

















