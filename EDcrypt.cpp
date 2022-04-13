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

int EDCrypt(int message, int &publicKey, int &nVal){


	return (edPow(message, publicKey) % nVal);

}
