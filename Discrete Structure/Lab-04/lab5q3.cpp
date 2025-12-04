#include<iostream>
using namespace std;

int fibo(int n)
{
	if ( n<= 1)
	{
	return n;
	}
	else 
	{
		return fibo(n-1) + fibo(n-2); 
	}
};

int main(void)
{
	int n = 10;
	cout << "Fibonacci of 10 is: " << fibo(n) << endl;
}
