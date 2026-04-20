#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
각 노드로부터 시작해 BFS로 그래프 탐색을 수행. 노드와 간선의 개수를 세어
노드의 개수 - 1 == 간선의 개수 가 성립하면 트리로 판정한다.
*/
void print(int step, int cnt)
{
	cout << "Case " << step << ": ";
	if(cnt == 0)
		cout << "No trees.\n";
	else if(cnt == 1)
		cout << "There is one tree.\n";
	else
		cout << "A forest of " << cnt << " trees.\n";
}

int main(void)
{
	int step = 1;
	int n, m;
	while (true)
	{
		cin >> n >> m;
		if(n==0 && m == 0)
			break;

		vector<vector<int>> adj(n+1);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		vector<bool> vis(n+1, false);
		queue<int> q;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			q.push(i);
			vis[i] = true;

			int nodeCnt = 0, edgeCnt = 0;
			while (!q.empty())
			{
				int cur = q.front(); q.pop();
				nodeCnt++;
				for (int& nxt : adj[cur])
				{
					edgeCnt++;
					if(vis[nxt]) continue;
					q.push(nxt);
					vis[nxt] = true;
				}
			}
			//양방향 그래프기 때문에 간선을 2로 나눠준다.
			if(nodeCnt - 1 == edgeCnt/2) ans++;
		}
		print(step, ans);
		step++;
	}

	return 0;
}