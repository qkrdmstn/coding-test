#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int EatFish(int& x, int& y, int size, vector<vector<int>>& board, int n)
{
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(n, -1));
	vector<pair<int, int>> fish;

	int minDist = 0x3f3f3f3f;
	q.push({ x, y });
	dist[x][y] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (dist[cur.first][cur.second] > minDist) break;
		if (board[cur.first][cur.second] > 0 && board[cur.first][cur.second] < size)
		{
			minDist = min(minDist, dist[cur.first][cur.second]);
			fish.push_back({ cur.first, cur.second });
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] > size || dist[nx][ny] >= 0) continue;
			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
	if (fish.empty()) return -1;

	//가장 위쪽, 왼쪽인 물고기 순으로 정렬합니다.
	sort(fish.begin(), fish.end());

	//물고기를 먹습니다.
	x = fish[0].first, y = fish[0].second;
	board[x][y] = 0;

	return minDist;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, x, y;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				x = i;
				y = j;
				board[i][j] = 0;
			}
		}
	}

	int size = 2;
	int cnt = 0;
	int time = 0;
	while (true)
	{

		int dist = EatFish(x, y, size, board, n);
		if(dist == -1) break;
		time+=dist;
		cnt++;
		if (cnt == size)
		{
			size++;
			cnt = 0;
		}
	}
	cout << time;
	return 0;
}