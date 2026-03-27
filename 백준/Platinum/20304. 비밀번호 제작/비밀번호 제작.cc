#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	queue<int> q;
	vector<int> dist(1000005, -1);
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		q.push(p);
		dist[p] = 0;
	}

	int depth = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front(); q.pop();
			
			for (int j = 0; j < 20; j++)
			{
				int nxt = cur ^ (1 << j);
				if(nxt > n) continue;
				if(dist[nxt] >= 0) continue;
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
		depth++;
	}

	cout << depth - 1;
	//BFS로 한 비트씩 다르게 이동하여, 최단 거리 방문된 2진수는 곧 안전도가 된다.
	// 즉, 시도된 비밀번호로부터 가장 최단거리로 해당 수에 도달했기 때문이다.
	// 그렇다면, 시도된 비밀번호로부터 가장 늦게 최단거리로 도달한 수가 안전도가 가장 높은 수이다.
	// 이때의 안전도는 BFS의 Depth라 할 수 있다.
	//비트마스킹(shift 및 xor 연산을 통해 안전 거리가 1인 수를 구하기)과 BFS만 떠올린다면 easy
	return 0;
}