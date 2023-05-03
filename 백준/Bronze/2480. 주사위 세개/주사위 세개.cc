#include<iostream>
using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int max;

	if (a == b && a == c)
		cout << 10000 + (a * 1000);
	else if (a == b || a == c)
		cout << 1000 + (a * 100);
	else if (b == c)
		cout << 1000 + (b * 100);
	else
	{
		max = a > b ? (a > c ? a : c) : (b > c ? b : c);
		cout << max * 100;
	}
	return 0;
}