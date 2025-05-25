#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> c[100'005];
long long ans[100'005];

queue<int> q;
bool vis[100'005];

void bfs()
{
	q.push(1);
	vis[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : c[cur]) {
			if (vis[nxt]) continue;
			ans[nxt] += ans[cur];
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if (p != -1)
			c[p].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int node, val;
		cin >> node >> val;
		ans[node] += val;
	}

	bfs();

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	return 0;
}