#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 32'005;

int n, m;
vector<int> adj[MXN];
int indeg[MXN];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) pq.push(i);
	}

	while (!pq.empty()){
		int cur = pq.top();
		pq.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) {
			indeg[nxt]--;
			if (indeg[nxt] == 0)
				pq.push(nxt);
		}
	}
	
	/*
	최소 힙을 통해 최적화
	*/
	return 0;
}