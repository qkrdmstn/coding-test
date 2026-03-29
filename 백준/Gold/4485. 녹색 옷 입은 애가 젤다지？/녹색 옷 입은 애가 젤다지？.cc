#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main(void)
{
	int n, step = 0;
	while (true)
	{
		step++;

		cin >> n;
		if (n == 0) break;

		vector<vector<int>> board(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		}

		vector<vector<int>> dist(n, vector<int>(n, INF));
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		pq.push({ board[0][0], 0, 0 });
		dist[0][0] = board[0][0];

		while (!pq.empty())
		{
			int curX, curY, cost;
			tie(cost, curX, curY) = pq.top(); pq.pop();
			if(dist[curX][curY] != cost) continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = curX + dx[i], ny = curY + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[curX][curY] + board[nx][ny] < dist[nx][ny])
				{
					dist[nx][ny] = dist[curX][curY] + board[nx][ny];
					pq.push({dist[nx][ny], nx, ny});
				}
			}
		}

		cout << "Problem " << step << ": " << dist[n-1][n-1] << "\n";
	}
	return 0;
}