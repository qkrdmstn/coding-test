#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> e(n+1, vector<int>());
	vector<bool> visited(n+1, false);
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for (auto nxt : e[cur])
		{
			if(visited[nxt]) continue;
			q.push(nxt);
			visited[nxt] = true;
			answer++;
		}
	}

	cout << answer;
	return 0;
}