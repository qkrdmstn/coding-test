#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(void)
{
	int n;
	cin >> n;

	//d[i][j] : i번째 줄의 j번째 수를 택하는 최솟/최댓값
    //d[0][j] : 이전 값
    //d[1][j] : 현재 계산할 값
	vector<vector<int>> maxD(2,vector<int>(3, 0));
	vector<vector<int>> minD(2,vector<int>(3, INF));
	vector<int> arr(3, 0);
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		maxD[0][i] = minD[0][i] = arr[i];
	}

	for (int i = 1; i < n; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		for (int j = 0; j < 3; j++)
		{
			//d[i][j]는 i-1번째 줄에서 j-1, j, j+1번째 수로부터 도달할 수 있다.
			for (int k = -1; k <= 1; k++)
			{
				int idx = j+k;
				if(idx < 0 || idx > 2) continue;
				minD[1][j] = min(minD[1][j], minD[0][idx] + arr[j]);
				maxD[1][j] = max(maxD[1][j], maxD[0][idx] + arr[j]);
			}
		}
		for (int j = 0; j < 3; j++)
		{
			minD[0][j] = minD[1][j];
			maxD[0][j] = maxD[1][j];

			minD[1][j] = INF;
			maxD[1][j] = 0;
		}
	}

	int minAns = INF;
	int maxAns = 0;
	for (int i = 0; i < 3; i++)
	{
		minAns = min(minAns, minD[0][i]);
		maxAns = max(maxAns, maxD[0][i]);
	}

	cout << maxAns << " " << minAns;
	return 0;
}