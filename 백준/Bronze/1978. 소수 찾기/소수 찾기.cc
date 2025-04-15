#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		bool isPrime = true;
		for (int j = 2; j < num; j++) {
			if (num % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime && num != 1)
			cnt++;
	}

	cout << cnt;
	return 0;
}