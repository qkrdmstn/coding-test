#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string a;
int board[1005][1005];
int d[1005][1005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			board[i + 1][j + 1] = a[j] - '0';
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				d[i][j] = min({ d[i - 1][j], d[i - 1][j - 1], d[i][j - 1] }) + 1;
				ans = max(ans, d[i][j]);
			}
		}
	}
	cout << ans * ans;

	/*
	설명:
	d[i][j]: i*j 크기의 board일 때, 정사각형의 최대 크기
	누적하면 현재 위치에서 사각형이 만들어지는지 확인 X,
	-> d[i][j] = 0일 경우 0으로 냅둠
	-> 1일 경우에 최소값 + 1로 해주기
	*/
	return 0;
}