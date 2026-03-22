#include <iostream>
using namespace std;

int offset[3] = {-1, 0, 1};

int main(void)
{

	int n;
	cin >> n;

	//DP[i][j]: i열의 j번째 숫자를 가지는 최대/최소의 수.
	//이때 메모리 제한에 의해 현재 및 다음 상태의 DP 테이블만 저장.
	int minDP[2][3];
	int maxDP[2][3];
	int board[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> board[i];
		minDP[0][i] = maxDP[0][i] = board[i];
	}

	for(int i=1; i<n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[j];

			//j번째 칸으로 내려올 수 있는 이전 층의 idx를 계산
			// 해당되는 수 중 최소/최대 값을 판별
			int mn = 0x3f3f3f3f;
			int mx = 0;
			for (int k = 0; k < 3; k++)
			{
				int idx = j + offset[k];
				if(idx < 0 || idx >= 3) continue;
				mn = min(mn, minDP[0][idx]);
				mx = max(mx, maxDP[0][idx]);
			}
			minDP[1][j] = mn + board[j];
			maxDP[1][j] = mx + board[j];
		}

		//다음 상태를 현재 상태로 변경
		for (int j = 0; j < 3; j++)
		{
			minDP[0][j] = minDP[1][j];
			maxDP[0][j] = maxDP[1][j];
		}
	}

	int minAns = 0x3f3f3f3f;
	int maxAns = 0;
	for (int j = 0; j < 3; j++)
	{
		maxAns = max(maxAns, maxDP[0][j]);
		minAns = min(minAns, minDP[0][j]);
	}
	cout << maxAns << " " << minAns << "\n";
	return 0;
}