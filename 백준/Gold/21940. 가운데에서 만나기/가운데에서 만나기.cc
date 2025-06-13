#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, k;
int dist[205][205];
vector<int> friends;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	//거리 INF 초기화
	for (int i = 1; i <= n; i++)
		fill(dist[i], dist[i] + n + 1, INF);
	
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	cin >> k;
	while (k--) {
		int c;
		cin >> c;
		friends.push_back(c);
	}

	//플로이드 알고리즘으로 모든 지역 쌍에 대해 거리 계산
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) 
				dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
		}
	}

	int minTime = INF;
	for (int x = 1; x <= n; x++) {
		int maxTime = 0;
		for (auto f : friends) {
			maxTime = max(maxTime, dist[f][x] + dist[x][f]);
		}
		if (maxTime < minTime)
			minTime = maxTime;
	}

	vector<int> ans;
	for (int x = 1; x <= n; x++) {
		int maxTime = 0;
		for (auto f : friends) {
			maxTime = max(maxTime, dist[f][x] + dist[x][f]);
		}
		if (maxTime == minTime)
			ans.push_back(x);
	}

	for (auto a : ans)
		cout << a << ' ';
	return 0;
}