#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	//d[i][j]: 아이템이 i개, 최대 무게가 j일 때 최대 가치
	vector<vector<int>> d(n + 1, vector<int>(k + 1, 0));
	vector<pair<int, int>> items(n + 1, { 0,0 }); //{무게, 가치}
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		items[i] = {w, v};
	}

	for (int i = 1; i <= n; i++)
	{
		int weight = items[i].first;
		int value = items[i].second;

		for (int j = k; j >= 0; j--)
		{
			//최대 무게보다 아이템 무게가 무거우면 담지 않고 이전 상태 가져오기
			if(j < weight) 
				d[i][j] = d[i-1][j];
			//담을 수 있으면, 1. 현재 아이템을 담고 가치를 높이는 것과
			//2. 담지 않고 이전 상태 가져오는 것 중 더 큰 것을 선택
			else
				d[i][j] = max(d[i-1][j], d[i-1][j-weight] + value);
		}
	}

	cout << d[n][k];
	return 0;
}