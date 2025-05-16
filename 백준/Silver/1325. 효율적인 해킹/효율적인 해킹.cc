#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[10005];
bool vis[10005];
vector<int> ans[10005];

int bfs(int start)
{
	queue<int> q;
	fill(vis, vis + n + 1 , false);
	
	q.push(start);
	vis[start] = true;

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;
		for (auto nxt: adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		//n1이 n2를 신뢰 -> n2 해킹 시 n1도 가능
		adj[n2].push_back(n1);
	}

	int maxCnt = 0;
	for (int st = 1; st <= n; st++) {
		int cnt = bfs(st);
		ans[cnt].push_back(st);
		maxCnt = max(maxCnt, cnt);
	}

	for (auto num : ans[maxCnt])
		cout << num << ' ';
	return 0;
}