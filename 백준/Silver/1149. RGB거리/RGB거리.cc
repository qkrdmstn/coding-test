#include <iostream>
using namespace std;

int n;
//d[i][j] i번째 집까지 칠할때 최소 비용, i는 j색으로 칠함
int d[1005][3]; //0:R, 1:G, 2:B
int r[1005], g[1005], b[1005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	
	d[1][0] = r[1];
	d[1][1] = g[1];
	d[1][2] = b[1];

	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
	}

	cout << min(d[n][0], min(d[n][1], d[n][2]));
	return 0;
}