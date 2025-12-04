#include<iostream>
using namespace std;

int amuln(int a, int n)
{
	if (n==0)
	{
		return 1;
	}	
	else
	{
		return a*(amuln(a,n-1));
	}
};

int main(void)
{
	int a = 2, n = 2, y = 0;
	y = amuln(a, n);
	cout << "a to pow n: " << y << endl;
}
