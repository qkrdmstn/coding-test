#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[105];
int dist[105];
vector<pair<int, int>> v; //{베이컨 수, 회원 번호}

int bfs(int start)
{
	queue<int> q;
	fill(dist, dist + n + 1 , -1);
	
	q.push(start);
	dist[start] = 0;

	int score = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt: adj[cur]) {
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
			//베이컨 수 합
			score += dist[nxt];
		}
	}
	return score;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	for (int st = 1; st <= n; st++)
		v.push_back({bfs(st), st});

	//베이컨 수, 회원번호 기준 오름차순 정렬
	sort(v.begin(), v.end());

	//베이컨 수 및 회원번호가 가장 작은 회원 출력
	cout << v.front().second;
	return 0;
}