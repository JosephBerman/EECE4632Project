#include <iostream>
#include <ap_int.h>
#include <math.h>

using namespace std;



int EDCrypt(int message, int &publicKey, int &nVal);

int main()
{
	cout << "\n********************************************\n" << " Starting ..." << "\n";



	int publicKey, privateKey, n;
	publicKey = 23;
	privateKey = 47;
	n = 143;
	int message = '~';
	printf("message: %d\n", message);

	int encrypted = EDCrypt(message,  publicKey, n);

	cout << "public: " << publicKey << endl;

	cout << "n: " << n << endl;
	cout << "public: " << privateKey << endl;



	printf("encrypted: %d\n", encrypted);

	encrypted = EDCrypt(encrypted,  privateKey, n);


	printf("decrypted: %d\n", encrypted);


return 0;
}
