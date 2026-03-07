#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for(int i=0; i<n; i++)
		cin >> board[i];

	vector<vector<int>> d(n, vector<int>(m, 0));
	for(int i=0; i<n; i++)
		d[i][0] = board[i][0] - '0';
	for (int i = 0; i < m; i++)
		d[0][i] = board[0][i] - '0';

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			//현재 위치가 1이라면 왼쪽, 왼쪽위, 위 중 가장 작은 크기의 사각형 + 1이다.
			if (board[i][j] == '1')
				d[i][j] = min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
			else
				d[i][j] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			ans = max(d[i][j],ans);
	}
	cout << ans*ans;
	return 0;
}