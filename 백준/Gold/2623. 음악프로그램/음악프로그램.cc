#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 32'005;

int n, m;
vector<int> adj[MXN];
int indegree[MXN];
queue<int> q;
vector<int> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt, cur, prev;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			cin >> cur;
			if (j != 0) {
				adj[prev].push_back(cur);
				indegree[cur]++;
			}
			prev = cur;
		}
	}

	//각 정점의 indegree count
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	//위상 정렬
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;
			//indegree가 0이면 큐에 push
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}

	if (ans.size() != n) cout << 0;
	else {
		for (auto v : ans)
			cout << v << '\n';
	}

	return 0;
}