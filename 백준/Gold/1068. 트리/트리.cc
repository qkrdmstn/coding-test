#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& tree, int root, int rmv, int n)
{
	int ans = 0;
	queue<int> q;
	vector<bool> vis(n, false);

	q.push(root);
	vis[root] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		int cnt = 0;
		for (auto nxt : tree[cur])
		{
			if(nxt == rmv || vis[nxt]) continue;
			cnt++;
			q.push(nxt);
			vis[nxt] = true;
		}
		if(cnt == 0) ans++;
	}
	return ans;
}

int main(void)
{
	int n, root, rmv;
	cin >> n;
	vector<vector<int>> tree(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if(p == -1)
			root = i;
		else
			tree[p].push_back(i);
	}	
	cin >> rmv;

	if(root == rmv) cout << 0;
	else cout << BFS(tree, root, rmv, n);
	return 0;
}