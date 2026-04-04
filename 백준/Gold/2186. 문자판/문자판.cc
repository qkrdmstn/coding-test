#include <iostream>
#include <string>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
string board[101];
int dp[105][105][90];

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	string word;
	cin >> word;

	int len = word.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(board[i][j] == word[len-1])
				dp[i][j][len-1] = 1;
		}
	}

	for (int spell = len - 1; spell >= 1; spell--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(board[i][j] != word[spell]) continue;
				for (int dir = 0; dir < 4; dir++)
				{
					for (int dist = 1; dist <= k; dist++)
					{
						int nx = i + dx[dir] * dist;
						int ny = j + dy[dir] * dist;

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(board[nx][ny] == word[spell - 1])
							dp[nx][ny][spell - 1] += dp[i][j][spell];
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
			if(board[i][j] != word[0]) continue;
			ans += dp[i][j][0];
		}
	}
	cout << ans;
	return 0;
}