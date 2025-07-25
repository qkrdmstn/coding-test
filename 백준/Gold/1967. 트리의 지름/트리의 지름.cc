#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int MXN = 10'005;

int n;
int mxDist, mxNode;
vector<pair<int, int>> adj[MXN];
bool vis[MXN];

void dfs(int cur, int dist)
{
	if (mxDist < dist) {
		mxDist = dist;
		mxNode = cur;
	}
	for (auto nxt : adj[cur]) {
		if (vis[nxt.first]) continue;
		vis[nxt.first] = true;
		dfs(nxt.first, dist + nxt.second);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		adj[p].push_back({ c,w });
		adj[c].push_back({ p,w });
	}
	
	vis[1] = true;
	dfs(1, 0);
	
	fill(vis, vis + n + 1, false);
	vis[mxNode] = true;
	dfs(mxNode, 0);
	cout << mxDist;
	return 0;

	/*
	트리의 지름은 아무 한 점에서 가장 멀리 간 다음, 
	그 점과 가장 멀리있는 점까지의 거리를 측정하면 된다.
	*/
}