#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	int maxH = 0, minTime = 0x3f3f3f3f;
	for (int h = 0; h <= 256; h++)
	{
		int remove = 0;
		int add = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(board[i][j] < h)
					add += h - board[i][j];
				else if(board[i][j] > h)
					remove += board[i][j] - h;
			}
		}

		if(add > b + remove) continue;
		int time = remove * 2 + add;
		if (time <= minTime)
		{
			minTime = time;
			maxH = max(maxH, h);
		}
	}

	cout << minTime << ' ' << maxH;
	return 0;
}