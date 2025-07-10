#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
ll n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	ll digit = 1;
	ll start = 1;
	while (true) {
		ll num = 9 * start;
		ll totalDigit = num * digit;
		if (k <= totalDigit) break;
		k -= totalDigit;
		start *= 10;
		digit++;
	}

	ll num = start + (k - 1) / digit;
	if (num > n) {
		cout << -1;
		return 0;
	}

	string str = to_string(num);
	cout << str[(k - 1) % digit];
	return 0;
}