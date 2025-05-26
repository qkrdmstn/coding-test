#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 105;

int n, m;
vector<int> root;
vector<pair<int, int>> adj[MXN]; //{부품, 개수}
queue<int> q;
int indeg[MXN];
int ans[MXN][MXN];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		adj[y].push_back({ x,k });
		indeg[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			root.push_back(i);
			ans[i][i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			int type = nxt.first;
			int num = nxt.second;

			//현재 부품을 만드는 데 필요한 기본 부품 * 다음 부품을 만드는데 필요한 현재 부품의 개수
			// -> 기본 부품으로 치환해서 다음 부품을 채워줌
			for (auto v : root)
				ans[type][v] += ans[cur][v] * num;

			indeg[type]--;
			if (indeg[type] == 0) q.push(type);
		}
	}

	for (auto v : root) {
		cout << v << ' ' << ans[n][v] << '\n';
	}
	return 0;
}