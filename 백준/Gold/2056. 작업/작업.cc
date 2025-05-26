#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MXN = 32'005;

int n;
vector<int> adj[MXN];
int indeg[MXN];
int dur[MXN];
int t[MXN];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> dur[i] >> cnt;
		while (cnt--) {
			int u;
			cin >> u;
			adj[u].push_back(i);
			indeg[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			t[i] = dur[i];
		}
	}

	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur]) {
			t[nxt] = max(t[nxt], t[cur] + dur[nxt]);
			indeg[nxt]--;
			if (indeg[nxt] == 0)
				q.push(nxt);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, t[i]);
	cout << ans;
	return 0;
}