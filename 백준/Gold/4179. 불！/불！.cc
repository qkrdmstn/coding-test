#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = { 0,1, 0,-1 };
int dy[4] = { 1,0,-1,0 };
int r, c;
bool fired[1005][1005];
int dist[1005][1005];
string board[1005];
queue<pair<int, int>> fireQueue;
queue<pair<int, int>> q;

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F')
			{
				fireQueue.push({ i,j });
				fired[i][j] = true;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'J')
			{
				q.push({ i,j });
				dist[i][j] = 1;
				board[i][j] = '.';
			}
		}
	}

	while (!q.empty())
	{
		// 불과 지훈이가 동시에 도착하면 안되기 때문에 불의 확산 시뮬레이션을 먼저 수행합니다.
		int qSize = fireQueue.size();
		for (int i = 0; i < qSize; i++)
		{
			auto cur = fireQueue.front(); fireQueue.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if(fired[nx][ny] || board[nx][ny] != '.') continue;
				fired[nx][ny] = true;
				fireQueue.push({nx, ny});
			}
		}

		qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			auto cur = q.front(); q.pop();
			if (cur.first == 0 || cur.first == r - 1 || cur.second == 0 || cur.second == c - 1)
			{
				cout << dist[cur.first][cur.second];
				return 0;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (dist[nx][ny] >= 1 || fired[nx][ny] || board[nx][ny] != '.') continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}

		//cout << "fire----------------------------------------------\n";
		//for (int i = 0; i < r; i++)
		//{
		//	for (int j = 0; j < c; j++)
		//	{
		//		cout.width(2);
		//		cout << fired[i][j];
		//	}
		//	cout << "\n";
		//}
		//cout << "dist----------------------------------------------\n";
		//for (int i = 0; i < r; i++)
		//{
		//	for (int j = 0; j < c; j++)
		//	{
		//		cout.width(2);
		//		cout << dist[i][j];
		//	}
		//	cout << "\n";
		//}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}