#include <iostream>
#include <vector>
using namespace std;

int k, hole;
vector<char> operation;

int VerticalFold(int cur)
{
	return (cur + 2) % 4;
}

int HorizontalFold(int cur)
{
	if (cur >= 2)
		return (cur + 1) % 2 + 2;
	else
		return (cur + 1) % 2;
}

int main(void)
{
	cin >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		char op;
		cin >> op;
		operation.push_back(op);
	}

	cin >> hole;
	int size = 1 << k;
	vector<vector<int>> paper(size, vector<int>(size, hole));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int x = i, y = j;
			int curXSize = size;
			int curYSize = size;

			for (auto& op : operation)
			{
				if (op == 'U')
				{
					//아래 절반이라면,
					if (x >= curXSize / 2)
					{
						paper[i][j] = VerticalFold(paper[i][j]);
						x = curXSize - 1 - x;
					}
					curXSize /= 2;
				}
				else if (op == 'D')
				{
					//위 절반이라면,
					if (x  < curXSize / 2 )
					{
						paper[i][j] = VerticalFold(paper[i][j]);
						x = curXSize - 1 - x;
					}
					curXSize /= 2;
					x -= curXSize; //모든 좌표 정규화
				}
				else if (op == 'L')
				{
					//오른쪽 절반이라면,
					if (y >= curYSize / 2)
					{
						paper[i][j] = HorizontalFold(paper[i][j]);
						y = curYSize - 1 - y;
					}
					curYSize /= 2;
				}
				else if (op == 'R')
				{
					//왼쪽 절반이라면,
					if (y < curYSize / 2)
					{
						paper[i][j] = HorizontalFold(paper[i][j]);
						y = curYSize - 1 - y;
					}
					curYSize /= 2;
					y -= curYSize; //모든 좌표 정규화
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << paper[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}