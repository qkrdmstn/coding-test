#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int k;
	cin >> k;

	while (k--)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> adj(v+1, vector<int>());

		//인접 리스트 생성 (양방향)
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		//BFS를 활용해 인접 노드에 다른 색깔을 칠합니다.
		//다음 노드가 이미 나와 같은 그룹에 속한다면 이분 그래프가 아닙니다.
		bool isPossible = true;
		queue<int> q;
		vector<int> color(v+1, -1);
		//그래프가 끊긴 경우를 고려해 모든 정점에서 시작합니다.
		for (int i = 1; i <= v; i++)
		{
			//이미 방문한 정점은 건너뜁니다.
			if(color[i] >= 0) continue;
			q.push(i);
			color[i] = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if(!isPossible) break;
				for (auto nxt : adj[cur])
				{
					//다음 노드가 이미 나와 같은 색을 가진다면 인접 노드와 같은 집합입니다.
					if(color[nxt] == color[cur])
						isPossible = false;
					if(color[nxt] >= 0) continue;
					q.push(nxt);
					color[nxt] = (color[cur] + 1) % 2;
				}
			}
		}
		if(isPossible) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}