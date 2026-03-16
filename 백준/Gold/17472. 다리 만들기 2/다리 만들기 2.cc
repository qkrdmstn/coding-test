#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int LabelingIsland(vector<vector<int>>& board, int N, int M)
{
	int cnt = 0;
	vector<vector<bool>> vis(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j] || board[i][j] == 0) continue;
			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({ i, j });
			cnt++;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				board[cur.first][cur.second] = cnt;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					q.push({ nx, ny });
					vis[nx][ny] = true;
				}
			}
		}
	}
	return cnt;
}

void BuildEdge(vector<tuple<int, int, int>>& edge, vector<vector<int>>& board, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0) continue;

			for (int dir = 0; dir < 4; dir++)
			{
				int x = i;
				int y = j;
				int dist = 0;
				int curLabel = board[i][j];

				while (true)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (board[nx][ny] != curLabel && board[nx][ny] != 0 && dist >= 2)
					{
						edge.push_back({ dist, board[i][j], board[nx][ny] });
						break;
					}
					if(board[nx][ny] != 0) break;
					dist++;
					x = nx;
					y = ny;
				}
			}
		}
	}
}

int find(int u, vector<int>& p)
{
	if(p[u] < 0) return u;
	return p[u] = find(p[u], p);
}

bool uni(int u, int v, vector<int>& p)
{
	u = find(u, p); v = find(v, p);
	if(u == v) return false;
	p[u] = v;
	return true;
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	//1. BFS를 활용한 각 섬 라벨링
	int islandCnt = LabelingIsland(board, N, M);

	//2. 다리 연결하기
	vector<tuple<int, int, int>> edge;
	BuildEdge(edge, board, N, M);

	//3. 최소신장트리 만들기
	sort(edge.begin(), edge.end());
	int ans = 0;
	int edgeCnt = 0;
	vector<int> p(islandCnt+1, -1);
	for (auto &e: edge)
	{
		int c, a, b;
		tie(c, a, b) = e;
		
		if (uni(a, b, p))
		{
			ans += c;
			edgeCnt++;
		}
		if(edgeCnt == islandCnt - 1) break;
	}
	if(edgeCnt != islandCnt - 1)
		cout << -1;
	else
		cout << ans;

	return 0;
}