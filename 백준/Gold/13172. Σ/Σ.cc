#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int PRIME = 1000000007;

ll Pow(ll a, ll exp)
{
	if (exp == 0) return 1;
	if (exp == 1) return a % PRIME;

	ll half = Pow(a, exp / 2);
	ll res = (half * half) % PRIME; // 1. 제곱 후 나머지 연산

	if (exp % 2 == 1) {
		res = (res * (a % PRIME)) % PRIME; // 2. 홀수일 때 추가 곱셈 후 나머지 연산
	}

	return res;
}

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	int m;
	cin >> m;


	// a/b(mod P)는 성립이 안되기 때문에 b의 역원(b^(P-2))를 계산해서
	//a*b^-1 (mod P)를 계산한다.
	ll sum = 0;
	for (int i = 0; i < m; i++)
	{
		int n, s;
		cin >> n >> s;
		int g = gcd(n, s);
		n /= g;
		s /= g;

		// s*n^(P-2) % PRIME
		ll inverseN = Pow(n, PRIME-2) % PRIME;
		sum = (sum + s * inverseN) % PRIME;
	}
	cout << sum;
	return 0;
}