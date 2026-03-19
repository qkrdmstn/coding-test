#include <iostream>
#include <vector>
using namespace std;

int offset[3] = {-1,0,1};
int main(void)
{
	int n;
	int board[3];
	int maxDp[2][3]; //dp[1][i]: i번째 위치에 도착할 때 최대/최소 값
	int minDp[2][3]; 

	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> board[i];
		maxDp[0][i] = minDp[0][i] = board[i];
	}

	//메모리 절약을 위해 입력 즉시 테이블 값 계산
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> board[j];

		for (int j = 0; j < 3; j++)
		{
			int minNum = 0x3f3f3f3f;
			int maxNum = 0;

			//j번째 자리로 내려갈 수 있는 이전행의 수를 순회
			for (int diff = 0; diff < 3; diff++)
			{
				int idx = j + offset[diff];
				if (idx < 0 || idx >= 3) continue;
				minNum = min(minNum, minDp[0][idx]);
				maxNum = max(maxNum, maxDp[0][idx]);
			}
			//가장 큰/작은 수를 각각 dp 테이블에 합산
			minDp[1][j] = board[j] + minNum;
			maxDp[1][j] = board[j] + maxNum;
		}
		//현재 테이블 값 이전으로 저장
		for (int j = 0; j < 3; j++)
		{
			minDp[0][j] = minDp[1][j];
			maxDp[0][j] = maxDp[1][j];
		}
	}

	int maxAns = 0;
	int minAns = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++)
	{
		minAns = min(minAns, minDp[0][i]);
		maxAns = max(maxAns, maxDp[0][i]);
	}
	cout << maxAns << " " << minAns;
	return 0;
}