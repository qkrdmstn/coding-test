#include <iostream>
using namespace std;

int n, m;
int d[100005];
int arr[100005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i-1] << '\n';
	}

	return 0;
}