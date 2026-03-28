#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> e[50];

int BFS(int start, int remove)
{
	int leafNode = 0;
	queue<int> q;
	bool vis[51] = {false};

	if(start == remove) return 0;

	q.push(start);
	vis[start] = true;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
        
		int cnt = 0;
		for (auto& nxt : e[cur])
		{
			if(vis[nxt] || nxt == remove) continue;
			q.push(nxt);
			vis[nxt] = true;
			cnt++;
		}
        //진행할 노드가 없으면 leafNode
		if(cnt == 0) leafNode++;
	}

	return leafNode;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	int root, remove;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if(num == -1) root = i;
		else e[num].push_back(i);
	}

	cin >> remove;
	cout << BFS(root, remove);


	return 0;
}