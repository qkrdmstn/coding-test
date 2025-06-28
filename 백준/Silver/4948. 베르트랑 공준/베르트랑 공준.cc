#include <iostream>
using namespace std;

const int MX = 123456 * 2;

int n;
bool isPrime[MX + 1];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(isPrime, isPrime + MX + 1, true);
	isPrime[1] = false;
	for (int i = 2; i * i <= MX; i++) {
		for (int j = i * i; j <= MX; j += i) {
			isPrime[j] = false;
		}
	}

	while (true) {
		cin >> n;
		if (!n) break;

		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i]) ans++;
		}
		cout << ans << '\n';
	}

	return 0;

}
