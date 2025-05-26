#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 32'005;

int n, m;
vector<int> adj[MXN];
int indegree[MXN];
vector<int> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}

	for (auto v : ans)
		cout << v << ' ';
	return 0;
}