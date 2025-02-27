#include <iostream>
using namespace std;

long long func1(long long a, long long b, long long m)
{
	if (b == 1) return a % m;

	long long num = func1(a, b / 2, m);
	long long num2 = num * num % m;
	//b=2k
	if (b % 2 == 0)
		return num2;
	//b=2k+1
	else 
		return (num2 * a) % m;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, m;
	cin >> a >> b >> m;
	cout << func1(a, b, m);
	return 0;
}