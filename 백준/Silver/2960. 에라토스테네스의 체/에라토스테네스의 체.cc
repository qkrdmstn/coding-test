#include <iostream>
using namespace std;

int n, k;
bool erase[1001];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (erase[j]) continue;
			erase[j] = true;
			cnt++;
			if (cnt == k) {
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}