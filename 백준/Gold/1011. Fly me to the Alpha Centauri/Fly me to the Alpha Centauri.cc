#include <iostream>
#include <cmath>
using namespace std;

long long solve(long long dist)
{
	return floor(2 * sqrt(dist) - 1e-9);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		cout << solve(y - x) << '\n';
	}
	return 0;
}