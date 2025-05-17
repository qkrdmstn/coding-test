#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int k, v, e;
vector<int> adj[20'005];
int group[20'005];

/*
시작 노드의그룹을 0으로 지정하고, 인접 노드를 (각 노드 그룹 + 1) % 2로 지정
-> 인접 노드는 0과 1을 번갈아가며 갖게 됨
이때, 다음 노드가 현재 노드와 같은 지점을 만나면 false를 반환
무사히 모든 노드를 순회하면 true를 반환
*/
bool solve()
{
	fill(group, group + v + 1, -1);

	for (int i = 1; i <= v; i++) {
		if (group[i] != -1) continue;

		queue<int> q;
		q.push(i);
		group[i] = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				if (group[nxt] != -1) {
					if (group[nxt] == group[cur])
						return false;
					else
						continue;
				}

				group[nxt] = (group[cur] + 1) % 2;
				q.push(nxt);
			}
		}
	}
	return true;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> k;
	while (k--) {
		cin >> v >> e;

		for (int i = 1; i <= v; i++)
			adj[i].clear();

		for (int i = 0; i < e; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			adj[n1].push_back(n2);
			adj[n2].push_back(n1);
		}

		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}