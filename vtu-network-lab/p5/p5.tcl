#create simulation event
set ns [ new Simulator ]

set tr [ open p5.tr w ]
set nf [ open p5.nam w ]

$ns trace-all $tr
$ns namtrace-all $nf

proc finish {} {
    global ns nf tr
	$ns flush-trace
	close $tr
	close $nf
	exec xgraph -lw 2 -bg white p50.xg -geometry 600*600 &
	exec xgraph -lw 2 -bg white p51.xg -geometry 600*600 &
	exit 0	
}
$ns color 1 "Orange"
$ns color 2 "Blue"

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

set tcp0 [ new Agent/TCP ]
$ns attach-agent $n(0) $tcp0

set ftp [ new Application/FTP ]
$ftp attach-agent $tcp0

#set the file size in packets
#$ftp0 set maxPkts _1000

set sink0 [ new Agent/TCPSink ]
$ns attach-agent $n(9) $sink0

$ns connect $tcp0 $sink0

set tcp1 [ new Agent/TCP ]
$ns attach-agent $n(3) $tcp1

set telnet [ new Application/Telnet ]
$telnet attach-agent $tcp1

set sink1 [ new Agent/TCPSink ]
$ns attach-agent $n(6) $sink1

$ns connect $tcp1 $sink1

$ftp set packetsize_ 500
$ftp set maxPkts_ 2000

$telnet set packetsize_ 500

$tcp0 set class_ 1
$tcp1 set class_ 2

set outFile50 [ open p50.xg w ]
set outFile51 [ open p51.xg w ]

$ns at 0.0 "plotCongestionWindow $tcp0 $outFile50"
$ns at 0.0 "plotCongestionWindow $tcp1 $outFile51"

$ns at 5.0 "$ftp start"
$ns at 5.0 "$telnet start"
$ns at 40.0 "$ftp stop"
$ns at 40.0 "$telnet stop"

proc plotCongestionWindow {tcpSource outFile} {
	global ns
	set intervalTime 0.1
	set now [$ns now]
	set cWindow [$tcpSource set cwnd_]
	puts $outFile "$now $cWindow"
	$ns at [expr $now + $intervalTime] "plotCongestionWindow $tcpSource $outFile"
}

$ns at 50.0 "finish"
$ns run


