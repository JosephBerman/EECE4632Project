#include <iostream>
#include <math.h>
#include <ap_int.h>


using namespace std;
typedef ap_uint<1024> edmessage;

#define BITS 16

int getGDC(int a, int b);
int main();
int modinv(int a, int m);
int modexp(edmessage base, edmessage exp, int modulo);
bool isCoprime(int e, int lcm);
int getCoprime(int lcm);
int getTotient(int x, int y);
int findLCM(int a, int b);
bool isPrime(int n);
edmessage edPow(edmessage base, int toPow);


/**
 * @brief
 *
 * @param n
 * @return true
 * @return false
 */
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


/**
 * @brief
 *
 * @param a
 * @param b
 * @return int
 */
int getGDC(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

/**
 * @brief
 *
 * @param a
 * @param m
 * @return int
 */
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

/**
 * @brief
 *
 * @param base
 * @param exp
 * @param modulo
 * @return int
 */
int modexp(edmessage base, edmessage exp, int modulo) {
	edmessage sol = 1;
    while(exp > 0) {
        //cout << "base: " << base << endl;
        //cout << "exp: " << exp << endl;
        //cout << "modulo: " << modulo << endl;

        if(exp % 2 == 1) {
            //cout << "sol = " << sol << " * " << base << " % " << modulo << endl;
            sol = (sol * base) % modulo;
        }
        exp = exp >> 1;
        //cout << "base = " << base << " * " << base << " % " << modulo << endl;
        edmessage base = (base * base) % modulo;
        //cout << "new base: " << base << endl;
        //cout << "--------------------------------" << endl;

    }
    return sol;
}

/**
 * @brief
 *
 * @param e
 * @param lcm
 * @return true
 * @return false
 */
bool isCoprime(int e, int lcm) {
    if(isPrime(e)) {
        return getGDC(e, lcm) == 1;
    }
}

/**
 * @brief Calculate a coprime of the least common factor
 *
 * @param lcm Least common factor
 * @return A coprime of lcm
 */
int getCoprime(int lcm) {
    for(int i = lcm; i > 2; i--) {
        if(isCoprime(i, lcm) == true) {
            return i;
        }
    }
}

/**
 * @brief Calculates the least common multiple of a and b
 *
 * @param a First integer input
 * @param b Second integer input
 * @return The least common multiple of a and b
 */
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


edmessage edPow(edmessage base, int toPow){
	edmessage count;
	count = 1;
	for(int i =0; i < toPow; i++){
		count *= base;
	}
	return count;
}


int test(int message, int &privateKey, int &publicKey, int &n) {
    int p = 11;
    int q = 17;

    cout << "p: " << p << " q: " << q << endl;

     n = p * q;
    cout << "n: " << n << endl;

    int lcm = findLCM(p, q);
    cout << "lcm: " << lcm << endl;

    int coprime = 23; //getCoprime(lcm);
    cout << "coprime: " << coprime << endl;

    int d = modinv(coprime, lcm);
    cout << "d: " << d << endl;
    privateKey = d;
    publicKey = coprime;
    cout << "Original message: " << message << endl;


    cout << "String message converted to ints: ";


    cout << endl;



     cout << "Message: " << message << endl;
     // edmessage encryptedMessage = fmod((edmessage)pow(message, coprime), n);
    int  encryptedMessage = edPow((edmessage)message, coprime) % n;
     cout << "Encryptd Message: " << encryptedMessage << endl;


    //  edmessage decryptedMessage = fmod((edmessage)pow(encryptedMessage, d),n);
      edmessage decryptedMessage = edPow(encryptedMessage, d) % n;
      cout << "Decrypted Message: " << decryptedMessage << endl;

      return encryptedMessage;
}
