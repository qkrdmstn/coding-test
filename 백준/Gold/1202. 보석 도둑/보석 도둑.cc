#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using  namespace std;

/*
가방을 오름차순 정렬 후, 각 가방에 담을 수 있는 보석을 가치 기준 최대 힙에 넣는다.
최대 힙에서 보석을 하나 뽑아 택한다.
*/
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jewel;
	vector<int> bag;

	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jewel.push_back({ m, v });
	}
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		bag.push_back(c);
	}

	sort(jewel.begin(), jewel.end(), cmp);
	sort(bag.begin(), bag.end());

	int cur = 0;
	long long ans = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++)
	{
		while (cur < n && jewel[cur].first <= bag[i])
		{
			pq.push(jewel[cur].second);
			cur++;
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}