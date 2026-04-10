#include <iostream>
#include <string>
#include <vector>
using namespace std;
string board[101];
string target;
int dp[105][105][105];

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

	for (int i = len - 2; i >= 0; i--)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (board[x][y] == target[i])
				{
					for (int dir = 0; dir < 4; dir++)
					{
						for (int dist = 1; dist <= k; dist++)
						{
							int nx = x + dx[dir] * dist;
							int ny = y + dy[dir] * dist;
							if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
							if(board[nx][ny] == target[i+1])
								dp[x][y][i] += dp[nx][ny][i+1];
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (board[x][y] == target[0])
				ans += dp[x][y][0];
		}
	}
	cout << ans;
	return 0;
}