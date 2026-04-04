#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LowerBound(int x, vector<int>& arr)
{
	int st = 0;
	int ed = arr.size() - 1;

	int ans = 0;
	while (st <= ed)
	{
		int mid = st + (ed - st) / 2;
		if (arr[mid] >= x)
		{
			ans = mid;
			ed = mid - 1;
		}
		else
			st = mid + 1;
	}

	return ans;
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> space(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for(int j=0; j<n; j++)
			cin >> space[i][j];
	}

	vector<vector<int>> sortedSpace(space);
	for (int i = 0; i < m; i++)
	{
		sort(sortedSpace[i].begin(), sortedSpace[i].end());
		sortedSpace[i].erase(unique(sortedSpace[i].begin(), sortedSpace[i].end()), sortedSpace[i].end());
	}

	for (int i = 0; i < m; i++)
	{
		for(int j=0; j<n; j++)
			//space[i][j] = lower_bound(sortedSpace[i].begin(), sortedSpace[i].end(), space[i][j]) - sortedSpace[i]. begin();
			space[i][j] = LowerBound(space[i][j], sortedSpace[i]);
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if(space[i] == space[j]) ans++;
		}
	}
	cout << ans;
	return 0;
}