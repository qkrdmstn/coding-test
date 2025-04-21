#include <iostream>
#include <vector>
using namespace std;
const int m = 123456 * 2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> state(m + 1, true);
	state[1] = false;
	for (int i = 2; i <= m; i++) {
		for (int j = 2*i; j <= m; j += i) {
			if (!state[j]) continue;
			state[j] = false;
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n+1; i <= 2*n; i++) {
			if (state[i]) 
				cnt++;
		}
		cout << cnt << '\n';
	}
}