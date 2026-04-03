#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[10'005];
int maxNode, maxDist;

void DFS(int st, int dist, vector<bool>& vis)
{
	if (dist > maxDist)
	{
		maxDist = dist;
		maxNode = st;
	}

	for (auto nxt : adj[st])
	{
		int node, cost;
		tie(node, cost) = nxt;
		if(vis[node]) continue;
		vis[node] = true;
		DFS(node, dist + cost, vis);
		vis[node] = false;
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<bool> vis(n+1, false);
	vis[1] = true;
	DFS(1, 0, vis);


	fill(vis.begin(), vis.end(), false);
	vis[maxNode] = true;
	DFS(maxNode, 0, vis);
	cout << maxDist;
	return 0;
}