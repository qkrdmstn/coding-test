#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> adj[55];
int dist[55];
vector<int> scores[55];

int bfs(int start)
{
	queue<int> q;
	fill(dist, dist + n + 1 , -1);
	
	q.push(start);
	dist[start] = 0;

	int score = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt: adj[cur]) {
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
			score = dist[nxt];
		}
	}
	return score;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (true) {
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 == -1 && n2 == -1) break;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	for (int st = 1; st <= n; st++) {
		scores[bfs(st)].push_back(st);
	}

	for (int i = 1; i <= n; i++) {
		if (!scores[i].empty()) {
			sort(scores[i].begin(), scores[i].end());
			cout << i << ' ' << scores[i].size() << '\n';
			for (auto num : scores[i])
				cout << num << ' ';
			return 0;
		}
	}
	
	return 0;
}