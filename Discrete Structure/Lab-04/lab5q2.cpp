#include<iostream>
using namespace std;

int modExp(int b, int n, int m) // 2, 5, 5
{
    int result = 1; //result =  1
    b = b % m; // 2 % 5 = 2

    while (n > 0) { 
        if (n % 2 == 1) // 5 % 2 = 1	
            result = (result * b) % m; // result = (1 * 2) % 5 = 2  

        b = (b * b) % m; // b = (2 * 2) % 5 == 4	// b = (4 * 4) % 5 = 1
        n = n / 2; // n = 5 / 2 = 2	// n = 2 / 2 = 0
    }

    return result;
};

int main(void)
{
	int b = 2, n = 5, m = 5, mod = 0;
	mod = modExp(b, n , m);
	cout << "2 POW 5 MOD 5: " << mod << endl;
}
