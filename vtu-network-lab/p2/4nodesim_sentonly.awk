#! /use/bin/awk -f
BEGIN {
	tcp_pkt_Drop = 0;
	cbr_pkt_Drop = 0;
	tcp_pkt_Sent = 0;
	cbr_pkt_Sent = 0;
	#tcp_pkt_DlR = 0;
	#cbr_pkt_DlR = 0;
	tcp_pkt_DrR = 0;
	cbr_pkt_DrR = 0;
}
{	if(($1 == "d") && ($5 == "tcp")) { tcp_pkt_Drop++; }
	if(($1 == "d") && ($5 == "cbr")) { cbr_pkt_Drop++; }
	if(($1 == "+") && ($3 == "0") && ($4 == "2")) { tcp_pkt_Sent++; }
	if(($1 == "+") && ($3 == "1") && ($4 == "2")) { cbr_pkt_Sent++; }
}
END {
	#tcp_pkt_DlR = ( tcp_pkt_Sent - tcp_pkt_Drop ) / tcp_pkt_Sent;
	#cbr_pkt_DlR = ( cbr_pkt_Sent - cbr_pkt_Drop ) / cbr_pkt_Sent;
	tcp_pkt_DrR = tcp_pkt_Drop / tcp_pkt_Sent;
	cbr_pkt_DrR = cbr_pkt_Drop / cbr_pkt_Sent;
	#printf("TCP packet delivery ratio = %f\n",tcp_pkt_DlR);
	#printf("CBR packet delivery ratio = %f\n",cbr_pkt_DlR);
	printf("TCP packet drop ratio = %f\n",tcp_pkt_DrR);
	printf("CBR packet drop ratio = %f\n",cbr_pkt_DrR);
	#printf("Number of TCP packet sent = %d\n",tcp_pkt_Sent);
	#printf("Number of CBR packet sent = %d\n",cbr_pkt_Sent);
}
