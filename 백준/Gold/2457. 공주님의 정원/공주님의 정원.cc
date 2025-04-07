#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
pair<int, int> p[100005];

bool Compare(pair<int, int> a, pair<int, int> b)
{
	if (a.X == b.X)
		return a.Y < b.Y;
	return a.X < b.X;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int startM, startD, endM, endD;
		cin >> startM >> startD >> endM >> endD;
		p[i] = { startM * 100 + startD, endM * 100 + endD };
	}
	sort(p, p + n, Compare);

	int t = 301;
	int idx = 0;
	int ans = 0;
	while (t <= 1130) {
		int max_end = t;
		while(idx < n && p[idx].X <= t){
			max_end = max(max_end, p[idx].Y);
			idx++;
		}
		if (max_end == t) {
			cout << 0;
			return 0;
		}
		t = max_end;
		ans++;
	}
	cout << ans;
	return 0;
}