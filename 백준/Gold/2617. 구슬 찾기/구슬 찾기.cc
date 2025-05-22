#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> upperGraph[105];
vector<int> lowerGraph[105];
bool ans[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		upperGraph[b].push_back(a);
		lowerGraph[a].push_back(b);
	}

	int mid = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		queue<int> q;
		bool vis[105];
		fill(vis, vis + n + 1, false);

		q.push(i);
		vis[i] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : upperGraph[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
				cnt++;
			}
		}
		if (cnt >= mid)
			ans[i] = true;
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		queue<int> q;
		bool vis[105];
		fill(vis, vis + n + 1, false);

		q.push(i);
		vis[i] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : lowerGraph[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
				cnt++;
			}
		}
		if (cnt >= mid)
			ans[i] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i]) cnt++;
	}
	cout << cnt;

	return 0;
}