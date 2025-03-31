#include <iostream>
using namespace std;

int n;
int d[501][501];
int arr[501][501];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> arr[i][j];
		}
	}

	d[1][0] = arr[1][0];
	d[2][0] = d[1][0] + arr[2][0];
	d[2][1] = d[1][0] + arr[2][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i][j] = d[i - 1][j] + arr[i][j];
			if (j - 1 >= 0 && d[i][j] < d[i - 1][j - 1] + arr[i][j])
				d[i][j] = d[i - 1][j - 1] + arr[i][j];
		}
	}

	int ans = d[n][0];;
	for (int i = 1; i < n; i++)
		ans = max(ans, d[n][i]);
	cout << ans;
	return 0;
}