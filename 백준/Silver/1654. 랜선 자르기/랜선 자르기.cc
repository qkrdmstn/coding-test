#include <iostream>
using namespace std;

typedef long long ll;

int k, n;
int a[10005];

//dist로 구할 수 있는 랜선의 갯수
int solve(ll dist)
{
	ll result = 0;
	for (int i = 0; i < k; i++)
		result += a[i] / dist;
	return result;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> a[i];

	//이분탐색
	ll s = 1;
	ll e = 0x7fffffff; //2^32 - 1
	while (s < e) {
		ll m = (s + e + 1) / 2;
		if (solve(m) >= n)
			s = m;
		else
			e = m - 1;
	}
	cout << s;

	return 0;
}