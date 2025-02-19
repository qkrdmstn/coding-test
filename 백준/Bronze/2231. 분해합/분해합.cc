#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num = i;
		
		int digitSum = 0;
		while (num) {
			digitSum += num % 10;
			num /= 10;
		}

		int ans = digitSum + i;
		if (ans == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}