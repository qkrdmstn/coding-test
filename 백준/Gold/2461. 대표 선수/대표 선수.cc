#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m;
int ans = 0x7fffffff;
int state[1005];
vector<pair<int, int>> a;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			a.push_back({ num, i });
		}
	}
	sort(a.begin(), a.end());

	int cnt = 0, ed = 0;
	for (int st = 0; st < n * m; st++) {
		while (cnt < n && ed < n * m) {
			if (state[a[ed].Y] == 0) cnt++;
			state[a[ed].Y]++;
			ed++;
		}

		if (cnt != n) break;
		ans = min(ans, a[ed - 1].X - a[st].X);
		
		state[a[st].Y]--;
		if (state[a[st].Y] == 0)
			cnt--;
	}

	cout << ans;
	return 0;
	/*
	(능력치, 반)을 묶어, 능력치를 우선으로 정렬
	각 반의 학생이 한 명 이상 포함되도록 투 포인터 이동
	정렬된 배열이므로, 포인터의 시작과 끝이 능력치 최대, 최소를 의미
	*/
}