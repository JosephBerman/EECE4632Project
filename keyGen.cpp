#include <math.h>
#include <ap_int.h>
#include "ap_axi_sdata.h"


struct rsaKeyGen {
    int pub, priv, n;
};
typedef struct rsaKeyGen Struct;

bool isPrime(int n) {
    if(n == 0 || n == 1) {
        return false;
    }

    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            return false;
        }

    }
    return true;
}

int getGDC(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int modinv(int a, int m) {
    int m0 = m;
    int y = 0;
    int x = 1;
    if(m == 1) {
        return 0;
    }

    while(a > 1) {
        int q = a / m;  //calculate the quotient
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if(x < 0) {
        x += m0;
    }
    return x;
}

bool isCoprime(int e, int lcm) {
    if(isPrime(e)) {
        return getGDC(e, lcm) == 1;
    }
}

int getCoprime(int lcm) {
    for(int i = lcm; i > 2; i--) {
        if(isCoprime(i, lcm) == true) {
            return i;
        }
    }
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
    while (true)
    {
        if(greater % a == 0 && greater % b == 0) {
            lcm = greater;
            break;
        }
        greater++;
    }
    return lcm;
}

int generateModulo(int p, int q) {
	int n = p * q;


	return n;
}

int generatePublicKey() {
	int e = 23;
	return e;
}

int generatePrivateKey(int e, int lcm) {
	int d = modinv(e, lcm);

	return d;
}

Struct rsaKeyGen() {
	Struct k;
	int p = 11;
	int q = 13;
	int n = generateModulo(p, q);
	int e = generatePublicKey();
	int lcm = findLCM(p, q);
	int d = generatePrivateKey(e, lcm);
	k.pub = generatePublicKey();
	k.priv = generatePrivateKey(e, lcm);
	k.n = n;

	return k;
}

void keyGen(int &priv, int &pub, int &n) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE axis port=priv
	#pragma HLS INTERFACE axis port=pub
	#pragma HLS INTERFACE axis port=n
	Struct keys = rsaKeyGen();
	priv = keys.priv;
	pub = keys.pub;
	n = keys.n;
}



