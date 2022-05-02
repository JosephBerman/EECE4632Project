#include <iostream>
#include <math.h>
#include <ap_int.h>


typedef ap_uint<512> edmessage;



edmessage edPow(int base, int &toPow){
	edmessage count;
	count = 1;
	for(int i =0; i < toPow; i++){
		count *= base;
	}
	return count;
}

void EDCrypt(int message, int Key, int &nVal, int &out){
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=key
#pragma HLS INTERFACE axis port=nVal
#pragma HLS INTERFACE axis port=message
#pragma HLS INTERFACE axis port=out

	out = edPow(message, Key) % nVal;

}
