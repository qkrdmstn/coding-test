#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jewel(n);
	for(int i=0; i<n; i++)
		cin >> jewel[i].first >> jewel[i].second;

	vector<int> bag(k);
	for(int i=0; i<k; i++)
		cin >> bag[i];

	sort(jewel.begin(), jewel.end(), cmp);
	sort(bag.begin(), bag.end());

	int cnt = 0;
	long long ans = 0;
	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < k; i++)
	{
		while (jewel[cnt].first <= bag[i] && cnt < n)
		{
			pq.push(jewel[cnt].second);
			cnt++;
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