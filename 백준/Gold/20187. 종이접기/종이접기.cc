#include <iostream>
#include <vector>
using namespace std;

int standard[2][2] = { {0, 1}, {2, 3} };
int main(void)
{
	int k, hole;
	cin >> k;
	vector<char> op(2 * k);
	for (int i = 0; i < 2 * k; i++)
		cin >> op[i];
	cin >> hole;

	pair<int, int> initPos;
	if (hole == 0)
		initPos = { 0,0 };
	else if (hole == 1)
		initPos = { 0,1 };
	else if (hole == 2)
		initPos = { 1,0 };
	else
		initPos = { 1,1 };

	int n = 1 << k;
	vector<vector<pair<int, int>>> board(n + 1, vector<pair<int, int>>(n + 1, initPos));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int curXSize = n;
			int curYSize = n;
			int cx = i, cy = j;

			for (auto& o : op)
			{
				if (o == 'U')
				{
					if (curXSize / 2 <= cx)
					{
						board[i][j].first = 1 - board[i][j].first;
						cx = curXSize - 1 - cx;
					}
					curXSize /= 2;
				}
				else if (o == 'D')
				{
					if (curXSize / 2 > cx)
					{
						board[i][j].first = 1 - board[i][j].first;
						cx = curXSize - 1 - cx;
					}
					curXSize /= 2;
					cx -= curXSize;
				}
				else if (o == 'L')
				{
					if (curYSize / 2 <= cy)
					{
						board[i][j].second = 1 - board[i][j].second;
						cy = curYSize - 1 - cy;
					}
					curYSize /= 2;
				}
				else if (o == 'R')
				{
					if (curYSize / 2 > cy)
					{
						board[i][j].second = 1 - board[i][j].second;
						cy = curYSize - 1 - cy;
					}
					curYSize /= 2;
					cy -= curYSize;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = board[i][j].first;
			int y = board[i][j].second;
			cout << standard[x][y] << " ";
		}
		cout << "\n";
	}
	return 0;
}