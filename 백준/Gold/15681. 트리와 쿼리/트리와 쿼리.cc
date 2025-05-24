#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, r, q;
vector<int> adj[100'005];
bool vis[100'005];
int ans[100'005];

int subtree(int cur)
{
	vis[cur] = true;
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		ans[cur] += subtree(nxt);
	}
	ans[cur]++;
	return ans[cur];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	subtree(r);

	for (int i = 0; i < q; i++) {
		int st;
		cin >> st;
		cout << ans[st] << '\n';
	}
	/*
	1. 루트부터 트리 순회를 수행하여 각 노드의 부모를 찾기.
	2. 주어진 쿼리부터 부모를 제외한 방향으로 순회하여 서브트리 노드 개수 세기
	-> 시간 초과

	dfs를 통해 루트부터 재귀적으로 순회 -> 순회할 때마다 cnt 증가해서 리턴
	-> 각 노드의 서브트리 노드 개수를 세는 것이 가능해짐
	*/
	return 0;
}