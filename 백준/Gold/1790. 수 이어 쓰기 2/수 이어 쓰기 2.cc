#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
int main(void)
{
	int n, k;
	cin >> n >> k;

	ll digit = 1;
	ll start = 1;
	while (true)
	{
		ll totalDigit = 9 * start * digit;
		if (k <= totalDigit) break;
		k -= totalDigit;
		start *= 10;
		digit++;
	}

	ll number = start + (k - 1) / digit;
	if (number > n)
	{
		cout << -1;
		return 0;
	}

	string ans = to_string(number);
	cout << ans[(k - 1) % digit];
	return 0;
}