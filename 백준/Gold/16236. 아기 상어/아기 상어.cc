#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//상좌우하 순으로 방문
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

const int INF = 0x3f3f3f3f;
int BFS(int curSize, pair<int, int>& curPos, vector<vector<int>>& board, int n)
{
	queue<pair<int ,int>> q;
	vector<vector<int>> dist(n, vector<int>(n, -1));

	q.push({curPos.first, curPos.second});
	dist[curPos.first][curPos.second] = 0;
	int minDist = INF;
	vector<pair<int ,int>> eatFish;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if(minDist < dist[cur.first][cur.second]) break;
		if (board[cur.first][cur.second] > 0 && board[cur.first][cur.second] <= 6 && board[cur.first][cur.second] < curSize)
		{
			minDist = dist[cur.first][cur.second];
			eatFish.push_back(cur);
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(dist[nx][ny] >= 0 || board[nx][ny] > curSize) continue; //나보다 크면 못 지나감

			q.push({nx, ny});
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	if(minDist == INF) return -1;
	sort(eatFish.begin(), eatFish.end());
	board[curPos.first][curPos.second] = 0;
	board[eatFish[0].first][eatFish[0].second] = 9;
	curPos = eatFish[0];

	return minDist;
}

int main(void)
{
	int n;
	cin >> n;

	pair<int, int> curPos;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 9)
				curPos = {i, j};
		}
	}

	int curSize = 2;
	int cnt = 0;
	int time = 0;
	while (true)
	{
		int dist = BFS(curSize, curPos, board, n);
		if(dist == -1) break;
		time += dist;
		cnt++;
		if (cnt == curSize)
		{
			curSize++;
			cnt = 0;
		}
	}
	cout << time;
	return 0;
}