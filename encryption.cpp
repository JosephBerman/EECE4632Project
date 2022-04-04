#include <ap_int.h>
#include <iostream>
//#include <stdlib.h>
//#include <time.h>
#include <math.h>


using namespace std;

#define BITS 16

int gcd(int a, int b) {

	if(a == 0)
		return b;
	if(b == 0)
		return a;

	if(a==b)
		return a;

	if(a>b)
		return gcd(a-b,b);
	return gcd(a,b-a);

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
int test() {
    //srand(time(NULL));

    int q = 13;
    int  p = 11;

    int n = p * q;
    printf("n: %d\n",n);
    int phi = getTotient(p, q);
    printf("phi: %d\n",phi);
    int lcm = findLCM(p, q);
    printf("lcm: %d\n",lcm);
    int coprime = getCoprime(lcm);
    printf("coprime: %d\n",coprime);
    int d = modInv(coprime, phi);

    printf("d: %d\n",d);
    int message = 2;

    cout << "Original Message: " << message << endl;
    double encryptedMessage = fmod((double)pow(message, coprime), n);
    cout << "Encrypted Message: " << encryptedMessage << endl;


   double decryptedMessage = fmod((double)pow(encryptedMessage, d),n);

    cout << "Decrypted Message: " << decryptedMessage << endl;


}
