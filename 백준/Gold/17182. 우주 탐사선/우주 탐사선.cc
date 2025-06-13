#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 100000;

int n, st;
int dist[15][15];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> st;
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, INF);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> dist[i][j];
		}
	}

	for (int mid = 0; mid < n; mid++) {
		for (int st = 0; st < n; st++) {
			for (int ed = 0; ed < n; ed++)
				dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
		}
	}

	vector<int> comb;
	for (int i = 0; i < n; i++) {
		if (i == st) continue;
		comb.push_back(i);
	}
	
	//순열을 통해 모든 방문 순서 조합을 테스트
	int ans = INF;
	do {
		int totalCost = dist[st][comb[0]];
		for (int i = 1; i < n - 1; i++)
			totalCost += dist[comb[i-1]][comb[i]];
		ans = min(ans, totalCost);
	} while (next_permutation(comb.begin(), comb.end()));

	cout << ans;
	return 0;
}