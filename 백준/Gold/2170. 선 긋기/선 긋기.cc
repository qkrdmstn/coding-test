#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
long long ans;
vector<pair<int, int>> line;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		line.push_back({ start, end });
	}

	sort(line.begin(), line.end());

	int idx = 0;
	int startTime;
	int curTime;
	while (true) {
		startTime = line[idx].X;
		curTime = line[idx].Y;
		idx++;
		while (idx < n && line[idx].X <= curTime) {
			if(line[idx].Y > curTime)
				curTime = line[idx].Y;
			idx++;
		}
		ans += curTime - startTime;
		if (idx >= n)
			break;
	}
	cout << ans;

	return 0;
}