#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, treeCnt;
vector<int> adj[100'005];
bool vis[100'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		queue<int> q;
		q.push(i);
		vis[i] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
		treeCnt++;
	}

	cout << (treeCnt - 1) + (m + treeCnt - 1) - (n - 1);

	/*
	그래프에 tree 그룹의 개수를 센 뒤, 각 그룹을 연결(treeCnt-1)한다.
	이후 현재 그래프의 간선 개수(=m+treeCnt-1)를 트리의 특성에 의해 n-1개로 맞춰야 한다.
	즉, (m + treeCnt - 1) - (n - 1)개의 간선을 제거한다.
	최종적으로 각 그룹을 연결(treeCnt - 1) + 간선 제거(m + treeCnt - 1) - (n - 1)의 횟수가
	소요된다.
	*/
	return 0;
}