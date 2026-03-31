#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long OFFSET = 1000000000;
int LowBound(int x, vector<int>& arr, int n)
{
	
	int st = 0;
	int ed = n-1;
	int ans = 0;
	while (st <= ed)
	{
		int mid = st + (ed - st) / 2;
		if (arr[mid] >= x)
		{
			ed = mid - 1;
			ans = mid;
		}
		else
			st = mid + 1;
	}

	return ans;
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	vector<bool> vis(2000000001, false);
	vector<int> sortedArr;
	for (auto a : arr)
	{
		if(vis[a + OFFSET]) continue;
		sortedArr.push_back(a);
		vis[a + OFFSET] = true;
	}
	sort(sortedArr.begin(), sortedArr.end());

	for (auto& a : arr)
	{
		int idx = LowBound(a, sortedArr, sortedArr.size());
		cout << idx << " ";
	}

	return 0;
}