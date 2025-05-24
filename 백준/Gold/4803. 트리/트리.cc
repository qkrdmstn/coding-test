#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

vector<int> adj[505];
bool vis[505];

bool isTree(int start)
{
	stack<pair<int, int>> q;
	q.push({ start,0 });
	vis[start] = true;

	bool isTree = true;
	while (!q.empty()) {
		int cur, par;
		tie(cur, par) = q.top();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (nxt == par) continue;
			if (vis[nxt])
				return false;
			q.push({ nxt, cur });
			vis[nxt] = true;
		}
	}
	return true;
	/*
	BFS 풀이, 부모도 아니고, 이미 방문한 노드라면 순환이 있음으로 판단
	-> tree X
	*/
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (true) {
		int n, m, cnt = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		fill(vis, vis + n + 1, false);
		for (int i = 1; i <= n; i++)
			adj[i].clear();

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			cnt += isTree(i);
		}

		cout << "Case " << t++ << ": ";
		if (cnt == 0) cout << "No trees.\n";
		else if (cnt == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";
	}

	return 0;
}