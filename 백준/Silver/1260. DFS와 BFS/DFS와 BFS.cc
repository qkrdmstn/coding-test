#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> adj[1005];
bool visDFS[1005];

void bfs()
{
	queue<int> q;
	bool vis[1005];
	fill(vis, vis + n + 1, false);

	q.push(v);
	vis[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
	cout << '\n';
}

void dfs(int node)
{
	visDFS[node] = true;
	cout << node << ' ';
	for (auto nxt : adj[node]) {
		if (visDFS[nxt]) continue;
		dfs(nxt);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	//그래프 순회할 때, 번호가 낮은 노드부터 접근할 수 있도록 정렬
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());


	dfs(v); cout << '\n';
	bfs();
	return 0;
}