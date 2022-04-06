#include <ap_int.h>

#include <iostream>
//#include <stdlib.h>
//#include <time.h>
#include <math.h>


using namespace std;

#define BITS 16

typedef ap_uint<1024> edmessage;

int gcd(int a, int b) {

	int c;
	while(b != 0){
		c = a&b;
		a = b;
		b = c;

	}


	return a;

}

int isCoprime(int e, int lcm) {
	return gcd(e, lcm) == 1;
}

int findLCM(int a, int b) {
	int greater;
	int lcm;
	a -= 1;
	b -= 1;

	if(a > b) {
		greater = a;
	} else {
		greater = b;
	}
	while(true) {
		if(((greater % a) == 0) && ((greater % b) == 0)) {
			lcm = greater;
			break;
		}
		greater++;
	}
	return lcm;
}


int modInv(int u, int v) {
	for(int i = 1; i < v; i++) {
		if((u % v) * (i % v) % v == 1) {
			return i;
		}
	}
}

int getCoprime(int lcm) {
	for(int i = 2; i < lcm; i++) {
		if (isCoprime(i, lcm) == true) {
			return i;
		}
	}
}

int getTotient(int x, int y) {
	return (x - 1) * (y - 1);
}

int getDval(int phi, int e) {
	for(int i = 0; i < e*25; i++) {
		if((e * i) % phi == 1) {
			return i;
		}
	}
}
/*
bool isPrime(int n) {
    int flag = 0;
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int generatePrimeNum(int numBits) {
	int num;
    int bit_num = pow(2,numBits);
	do {
		num = rand() % bit_num;
	} while (!isPrime(num));
	return num;
}
*/

edmessage edPow(edmessage base, int toPow){
	edmessage count;
	count = 1;
	for(int i =0; i < toPow; i++){
		count *= base;
	}
	return count;
}
int test() {
    //srand(time(NULL));

    int q = 11;
    int  p = 7;

    int n = p * q;


    int phi = getTotient(p, q);

    int lcm = findLCM(p, q);

    int coprime = getCoprime(lcm);

    int d = modInv(coprime, phi);


    cout << "d: " << d << endl;
    edmessage message = 6;

    cout << "Message: " << message << endl;
   // edmessage encryptedMessage = fmod((edmessage)pow(message, coprime), n);
    edmessage encryptedMessage = edPow((edmessage)message, coprime) % n;
    cout << "Encrypted Message: " << encryptedMessage << endl;


  //  edmessage decryptedMessage = fmod((edmessage)pow(encryptedMessage, d),n);
    edmessage decryptedMessage = edPow(encryptedMessage, d) % n;
    cout << "Decrypted Message: " << decryptedMessage << endl;


}
