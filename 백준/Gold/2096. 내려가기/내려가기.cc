#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int maxDP[2][3];
	int minDP[2][3];
	int board[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> board[i];
		minDP[0][i] = maxDP[0][i] = board[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> board[j];

		for (int j = 0; j < 3; j++)
		{
			minDP[1][j] = 0x3f3f3f3f;
			maxDP[1][j] = 0;
			for (int k = -1; k <= 1; k++)
			{
				int idx = j+k;
				if(idx < 0 || idx > 2) continue;
				minDP[1][j] = min(minDP[0][idx] + board[j], minDP[1][j]);
				maxDP[1][j] = max(maxDP[0][idx] + board[j], maxDP[1][j]);
			}
		}
		
		for (int j = 0; j < 3; j++)
		{
			minDP[0][j] = minDP[1][j];
			maxDP[0][j] = maxDP[1][j];
		}
	}

	int maxAns = 0, minAns = 0x3f3f3f3f;
	for (int j = 0; j < 3; j++)
	{
		maxAns = max(maxDP[0][j], maxAns);
		minAns = min(minDP[0][j], minAns);
	}
	cout << maxAns << " " << minAns;
}