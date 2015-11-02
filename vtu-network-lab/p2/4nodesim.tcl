#create simulation event

set ns [ new Simulator ]

#enabling tracing
set tr [ open out.tr w ]
set nf [ open out.nam w ]

#record the events to the trace file and animation files
$ns trace-all $tr
$ns namtrace-all $nf

#define the finish proc
proc finish {} {
	global ns nf tr
	$ns flush-trace
	close $tr
	close $nf
	exec nam out.nam
	exit 0
}
#create the nodes
set n0 [ $ns node ]
set n1 [ $ns node ]
set n2 [ $ns node ]
set n3 [ $ns node ]

#extra stuffs
$ns color 1 "Red"
$ns color 2 "Green"
$n2 color "Blue"
$n2 shape "hexagon"

#create the topology
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2.5Mb 20ms DropTail

#orientation of links
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

#set the queue limit between the nodes n2 and n3
$ns queue-limit $n2 $n3 4

#create the TCP agent and attach to the node n0
set tcp0 [ new Agent/TCP ]
$ns attach-agent $n0 $tcp0

#create the FTP source and attach to the TCP agent
set ftp0 [ new Application/FTP ]
$ftp0 attach-agent $tcp0

#set the file size in packets
#$ftp0 set maxPkts _1000

#create TCPSink agent and attach to node n3
set sink0 [ new Agent/TCPSink ]
$ns attach-agent $n3 $sink0

#connect the TCP agent and its sink agent
$ns connect $tcp0 $sink0
$tcp0 set class_ 1

#create the UDP agent and attach to the node n1
set udp0 [ new Agent/UDP ]
$ns attach-agent $n1 $udp0

#create the CBR traffic source and attach to the UDP agent
set cbr0 [ new Application/Traffic/CBR ]
$cbr0 attach-agent $udp0

#set the packet size and interval
$ns set interval_ 0.0005
$ns set packetsize_ 2000

#create a null agent to receive the CBR packet and attach to node n3
set null0 [ new Agent/Null ]
$ns attach-agent $n3 $null0

#connect the UDP and its null agent
$ns connect $udp0 $null0
$udp0 set class_ 2

#schedule the events
$ns at 1.0 "$cbr0 start"
$ns at 1.5 "$ftp0 start"
$ns at 4.0 "$ftp0 stop"
$ns at 4.5 "$cbr0 stop"

#call the finish procedure at the end of the simulator
$ns at 5.0 "finish"

$ns run
