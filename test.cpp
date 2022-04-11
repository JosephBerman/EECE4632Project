#include <iostream>
#include <ap_int.h>
#include <math.h>

using namespace std;

typedef ap_uint<1024> edmessage;

int test(int message, int &privateKey, int &publicKey, int &n);

int main()
{
	cout << "\n********************************************\n" << " Starting ..." << "\n";


	int publicKey, privateKey, n;
	int encrypted = test('~', privateKey, publicKey, n);
	cout << "public: " << publicKey << endl;
	cout << "private: " << privateKey << endl;
	cout << "n: " << n << endl;
return 0;
}
