#include <iostream>
#include <string>
using namespace std;

string board[105];
int dp[105][105][105];
string target;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	cin >> target;

	int len = target.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == target[len - 1])
				dp[i][j][len - 1] = 1;
		}
	}

	for (int l = len - 2; l >= 0; l--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] != target[l]) continue;

				for (int dir = 0; dir < 4; dir++)
				{
					for (int dist = 1; dist <= k; dist++)
					{
						int nx = i + dx[dir] * dist;
						int ny = j + dy[dir] * dist;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == target[l + 1])
							dp[i][j][l] += dp[nx][ny][l+1];
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(board[i][j] == target[0])
				ans += dp[i][j][0];
		}
	}
	cout << ans;
	return 0;
}