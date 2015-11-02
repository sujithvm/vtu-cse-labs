#! /usr/bin/awk -f
BEGIN {
	pkt_Del = 0;
	throughput = 0.0;
	trpt = 0.0;
}
{	
	if(($1 == "r") && ($3 == "_4_") && ($4 == "AGT") && ($7 == "tcp") && ($8 >= 1000)) 
	{ pkt_Del++; }
}
END {
	printf("Total number of packets delivered = %d\n",pkt_Del);
	throughput = (pkt_Del * 500 * 8) / 85.0;
	trpt = throughput * 0.000001;
	printf("Throughput = %f Mbps\n",trpt);
}
