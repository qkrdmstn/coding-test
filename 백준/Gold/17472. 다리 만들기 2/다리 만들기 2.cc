#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = {1,0,-1,0};

int NamingIsland(vector<vector<int>>& board, int n, int m)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	vector<vector<bool>> visIsland(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visIsland[i][j] || board[i][j] == 0) continue;
			q.push({ i, j });
			visIsland[i][j] = true;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				board[cur.first][cur.second] = cnt;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || visIsland[nx][ny]) continue;
					q.push({ nx, ny });
					visIsland[nx][ny] = true;
				}
			}
			cnt++;
		}
	}

	return cnt;
}

void GenBridges(vector<tuple<int, int, int>>& edge, vector<vector<int>>& board,int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0) continue;

			for (int dir = 0; dir < 4; dir++)
			{
				int r = i;
				int c = j;
				int dist = 0;

				while (true)
				{
					r += dx[dir];
					c += dy[dir];
					if (r < 0 || r >= n || c < 0 || c >= m) break;
					if (board[r][c] == 0) dist++;
					else
					{
						if (board[r][c] == board[i][j]) break;
						if (board[r][c] != board[i][j])
						{
							if (dist >= 2)
								edge.push_back({ dist, board[i][j], board[r][c] });
							break;
						}
					}
				}
			}
		}
	}
}

int find(int u, vector<int>& parent)
{
	if(parent[u] < 0) return u;
	else return parent[u] = find(parent[u], parent);
}

bool uni(int u, int v, vector<int>& parent)
{
	u = find(u, parent), v = find(v, parent);
	if(u==v)
		return false;
	parent[u] = v;
	return true;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n,vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<m; j++)
			cin >> board[i][j];
	}

	// 1. BFS를 활용해 각 섬에 대해 번호를 지정합니다.
	int islandCnt = NamingIsland(board, n, m) - 1;

	// 2. 각 섬마다 상하좌우 직선방향 검사를 통해 다른 섬에 도달하는 경우 다리를 세웁니다.  
	vector<tuple<int, int, int>> edge;
	GenBridges(edge, board, n, m);


	// 3. 크루스칼 알고리즘으로 최소 비용으로 모든 섬을 연결하는 최소신장트리를 구성합니다.
	sort(edge.begin(), edge.end());
	vector<int> parent(islandCnt + 1, -1);
	int ans = 0;
	int cnt = 0;
	for (auto& e : edge)
	{
		int c, a, b;
		tie(c, a, b) = e;
		if (uni(a, b, parent))
		{
			ans += c;
			cnt++;
		}
		if(cnt == islandCnt-1) break;
	}

	// 4. 선택된 다리의 개수가 v-1가 아니라면 모든 섬을 연결하지 못합니다.
	if(cnt != islandCnt -1) cout << -1;
	else cout << ans << "\n";
	return 0;
}