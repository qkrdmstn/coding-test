#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int adj[55][55];
vector<int> party[55];
vector<int> knows;
bool vis[55];
bool ans[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		knows.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		int numOfPeople;
		cin >> numOfPeople;

		int prv, nxt;
		cin >> prv;
		party[i].push_back(prv);

		while (--numOfPeople) {
			cin >> nxt;
			party[i].push_back(nxt);
			adj[nxt][prv] = 1;
			adj[prv][nxt] = 1;
		}
	}


	for (auto st : knows) {
		queue<int> q;
		fill(vis, vis + n + 1, false);

		q.push(st);
		vis[st] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			ans[cur] = true;
			for (int nxt = 1; nxt <= n; nxt++) {
				if (adj[cur][nxt] == 0 || vis[nxt]) continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (ans[party[i][j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << m - cnt;
	return 0;
}