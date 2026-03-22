#include <iostream>
using namespace std;

typedef long long ll;

const ll PRIME = 1'000'000'007;

ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

ll pow(ll num, ll exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return num % PRIME;

	if (exp % 2 == 0)
	{
		ll half = pow(num, exp/2);
		return (half * half) % PRIME;
	}
	else
	{
		ll half = pow(num, (exp-1)/2);
		return (((half * half) % PRIME) * num) % PRIME;
	}
}

int main(void)
{
	int m;
	cin >> m;

	ll ans = 0;
	while (m--)
	{
		ll n, s;
		cin >> n >> s;

		ll g = gcd(n, s);

		n/=g;
		s/=g;

		ll invN = pow(n, PRIME-2) % PRIME;
		ans += (s * invN) % PRIME;
		ans %= PRIME;
	}
	cout << ans;
	return 0;
}