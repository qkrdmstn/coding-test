#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Check(int len, vector<int>& pos)
{
	int prev = 0;
	int cnt = 0;
	for (int i = 0; i < pos.size(); i++)
	{
		int dist = pos[i] - prev;
		cnt += dist / len;
		if (dist % len == 0)
			cnt--;
		prev = pos[i];
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;
	vector<int> pos(n);
	for (int i = 0; i < n; i++)
		cin >> pos[i];
	pos.push_back(l);
	sort(pos.begin(), pos.end());

	int ans = 0;
	int st = 1;
	int ed = l;
	while (st <= ed)
	{
		int mid = st + (ed - st) / 2;
		if (Check(mid, pos) > m)
			st = mid + 1;
		else
		{
			ed = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}