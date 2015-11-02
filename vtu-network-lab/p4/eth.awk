#! /use/bin/awk -f
BEGIN {
	tcp_pkt_Del = 0;
	cbr_pkt_Del = 0;
	throughput = 0.0;
	trpt = 0.0;
	packetsize = 500;
	tot_pkt_Del = 0;
}
{	
	if(($1 == "+") && ($3 == "4") && ($4 == "5") && ($5 == "tcp")) { tcp_pkt_Del++; }
	if(($1 == "+") && ($3 == "4") && ($4 == "5") && ($5 == "cbr")) { cbr_pkt_Del++; }
	tot_pkt_Del = tcp_pkt_Del + cbr_pkt_Del;
}
END {
	throughput = (tot_pkt_Del * 500 * 8) / 16;
	trpt = throughput * 0.000001;
	printf("Number of TCP packets delivered = %d\n",tcp_pkt_Del);
	printf("Number of CBR packets delivered = %d\n",cbr_pkt_Del);
	printf("Throughput = %f Mbps\n",trpt);
}
