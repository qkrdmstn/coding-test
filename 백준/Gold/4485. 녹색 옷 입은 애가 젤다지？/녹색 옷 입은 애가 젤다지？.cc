#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(void)
{
	int n;
	int cnt = 1;
	while (true)
	{
		cin >> n;
		if(n == 0) break;

		int board[125][125];
		for (int i = 0; i < n; i++)
		{
			for(int j=0; j<n; j++)
				cin >> board[i][j];
		}

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		int dist[125][125];
		for(int i=0; i<n; i++)
			fill(dist[i], dist[i] + n, INF);
		pq.push({ board[0][0], 0, 0});
		dist[0][0] = board[0][0];

		while (!pq.empty())
		{
			int cost, cx, cy;
			tie(cost, cx, cy) = pq.top(); pq.pop();
			if(dist[cx][cy] != cost) continue;

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if(nx <0 || nx >= n || ny < 0 || ny >= n) continue;

				int nxtCost = board[nx][ny];
				if(dist[cx][cy] + nxtCost >= dist[nx][ny]) continue;
				dist[nx][ny] = dist[cx][cy] + nxtCost;
				pq.push({dist[nx][ny], nx, ny});
			}
		}

		cout << "Problem " << cnt << ": " << dist[n-1][n-1] << "\n";
		cnt++;
	}

	return 0;
}