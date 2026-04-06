#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edge[10'005];

void DFS(int st, vector<bool>& vis, int len, int& maxDist, int& maxNode)
{
	if (len > maxDist)
	{
		maxDist = len;
		maxNode = st;
	}

	for (auto nxt : edge[st])
	{
		if(vis[nxt.first]) continue;

		vis[nxt.first] = true;
		DFS(nxt.first, vis, len + nxt.second, maxDist, maxNode);
		vis[nxt.first] = false;
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >>c;
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
	}

	vector<bool> vis(n+1, false);
	int maxDist = 0;
	int maxNode = 0;
	vis[1] = true;
	DFS(1, vis, 0, maxDist, maxNode);

	vector<bool> vis2(n+1, false);
	vis2[maxNode] = true;
	DFS(maxNode, vis2, 0, maxDist, maxNode);
	cout << maxDist << "\n";
	return 0;
}