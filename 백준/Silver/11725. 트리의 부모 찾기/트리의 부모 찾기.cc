#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100'005];
int p[100'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (nxt == p[cur]) continue;
			p[nxt] = cur;
			q.push(nxt);
		}
	}

	for (int i = 2; i <= n; i++)
		cout << p[i] << '\n';
	return 0;
}