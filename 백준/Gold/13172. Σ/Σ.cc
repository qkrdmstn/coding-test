#include <iostream>
using namespace std;

typedef long long ll;

const int PRIME = 1'000'000'007;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll Pow(ll num, ll exp)
{
	if (exp == 0) return 1;
	else if (exp == 1) return num;

	ll half = Pow(num, exp / 2);
	if (exp % 2 == 0)
		return half * half % PRIME;
	else
		return ((half * half) % PRIME * num) % PRIME;
}

int main(void)
{

	int m;
	cin >> m;

	ll ans = 0;
	while (m--)
	{
		int n, s;
		cin >> n >> s;

		//기약분수
		int g = gcd(n, s);
		n /= g;
		s /= g;

		ll invN = Pow(n, PRIME - 2) % PRIME;
		ans = (ans + (s * invN) % PRIME) % PRIME;
	}
	cout << ans;
	return 0;
}