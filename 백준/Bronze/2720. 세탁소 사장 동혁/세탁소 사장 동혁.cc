#include<iostream>
#include<string>
using namespace std;


int main()
{
	int q = 25, d = 10, n = 5, p = 1;
	int nq, nd, nn, np, c;
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> c;
		nq = c / q;
		c -= nq * q;
		nd = c / d;
		c -= nd * d;
		nn = c / n;
		c -= nn * n;
		np = c / p;
		c -= np * p;

		cout << nq << " " << nd << " " << nn << " " << np << endl;
	}

}
