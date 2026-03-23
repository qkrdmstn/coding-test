#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(int len, vector<int>& pos, int n)
{
	int cnt = 0;
	int curPos = 0;
	for (int i = 0; i <= n; i++)
	{
		int dist = pos[i] - curPos;
		cnt += (dist-1)/len;
		curPos = pos[i];
	}
	return cnt;
}

int main(void)
{
	int n, m, l;
	cin >> n >> m >> l;

	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		pos.push_back(p);
	}
	pos.push_back(l);
	sort(pos.begin(), pos.end());

	int ans = 0;
	int st = 1;
	int ed = l;
	while (st <= ed)
	{
		int mid = st + (ed - st) / 2;
		if (check(mid, pos, n) > m)
			st = mid + 1;
		else
		{
			ans = mid;
			ed = mid - 1;
		}
	}
	cout << ans;
	return 0;
}