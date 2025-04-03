#include <iostream>
using namespace std;

int n;
//d[i][k] = 길이가 i일 때, 마지막 수가 k일 경우의 계단 수의 개수
//d[i][k] = d[i-1][k-1] + d[i-1][k+1] 이고, k가 0과 9일 때 예외 처리를 진행
long long d[102][10];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= 9; k++) {
			if (k != 0) d[i][k] += d[i - 1][k - 1];
			if (k != 9) d[i][k] += d[i - 1][k + 1];
			d[i][k] %= 1000000000;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	ans %= 1000000000;
	cout << ans;
	return 0;
}