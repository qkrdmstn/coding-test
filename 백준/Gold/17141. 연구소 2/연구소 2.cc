#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//놓아진 바이러스로부터 감염 시뮬레이션
int BFS(vector<int>& res, vector<pair<int, int>>& possiblePos, int board[][51], int n)
{
	queue<pair<int, int>> q;
	int dist[51][51] = {-1};
	for(int i=0; i<n; i++)
		fill(dist[i], dist[i] + n, -1);

	for (auto& r : res)
	{
		q.push({possiblePos[r].first, possiblePos[r].second});
		dist[possiblePos[r].first][possiblePos[r].second] = 0;
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || nx >= n || ny <0 || ny >= n) continue;
			if(dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(board[i][j] == 1) continue;
			if(dist[i][j] == -1) return 0x3f3f3f3f;
			ans = max(ans, dist[i][j]);
		}
	}
	return ans;
}

//바이러스를 놓을 수 있는 자리 중 m개를 고르는 조합 함수
void DFS(int st, int board[][51], vector<pair<int, int>>& possiblePos, int n, int m, vector<int>& res, int& ans)
{
	if (res.size() >= m)
	{
		ans = min(ans, BFS(res, possiblePos, board, n));
		return;
	}
	for (int i = st; i < possiblePos.size(); i++)
	{
		res.push_back(i);
		DFS(i+1, board, possiblePos, n, m, res, ans);
		res.pop_back();
	}
}

int main(void)
{
	int n, m, possibleCnt = 0;
	cin >> n >> m;

	int board[51][51];
	vector<pair<int, int>> possiblePos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				possiblePos.push_back({i, j});
		}
			
	}

	int ans = 0x3f3f3f3f;
	vector<int> res;
	DFS(0, board, possiblePos, n, m, res, ans);

	if(ans == 0x3f3f3f3f)
		cout << -1;
	else
		cout << ans;
	return 0;
}