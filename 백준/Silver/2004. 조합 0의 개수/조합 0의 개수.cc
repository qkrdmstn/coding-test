#include <iostream>
using namespace std;
typedef long long ll;

ll n, m, two, five;
ll find(ll num, int p)
{
	ll result = 0;
	while(num) {
		result += num / p;
		num /= p;
	}
	return result;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	two = find(n, 2) - find(m, 2) - find(n - m, 2);
	five = find(n, 5) - find(m, 5) - find(n - m, 5);
	cout << min(two, five);
	return 0;
}