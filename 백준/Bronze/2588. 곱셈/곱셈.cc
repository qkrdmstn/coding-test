#include<iostream>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;

	int n, n10, n100;
	n = b % 10;
	n10 = ((b % 100) - n)/10;
	n100 = (b - n10 - n)/100;

	cout << a * n << endl;
	cout << a * n10 << endl;
	cout << a * n100 << endl;
	cout << a * b << endl;

	return 0;
}