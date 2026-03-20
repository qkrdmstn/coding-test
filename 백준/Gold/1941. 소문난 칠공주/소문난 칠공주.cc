#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int ConvertCoord1D(int x, int y)
{
	return (x * 5) + y;
}

pair<int, int> ConvertCoord2D(int x)
{
	pair<int, int> res = { x / 5, x % 5 };
	return res;
}

void DFS(int cur, vector<int>& result, vector<vector<int>>& results)
{
	if (result.size() >= 7)
	{
		results.push_back(result);
		return;
	}

	for (int i = cur; i < 25; i++)
	{
		result.push_back(i);
		DFS(i + 1, result, results);
		result.pop_back();
	}
}

bool BFS(vector<string>& board, vector<int>& result)
{
	bool vis[5][5] = { false };
	bool isPicked[5][5] = { false };

	for (auto& r : result)
		isPicked[r / 5][r % 5] = true;

	queue<pair<int, int>> q;
	int cx = result[0] / 5;
	int cy = result[0] % 5;

	q.push({ cx, cy });
	vis[cx][cy] = true;

	int cnt = 0;
	int sCnt = 0;
	while (!q.empty())
	{
		tie(cx, cy) = q.front(); q.pop();

		cnt++;
		if (board[cx][cy] == 'S') sCnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (vis[nx][ny] || !isPicked[nx][ny]) continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
		}
	}

	if (cnt == 7 && sCnt >= 4) return true;
	else return false;
}

int main(void)
{
	vector<string> board(5);
	for (int i = 0; i < 5; i++)
		cin >> board[i];

	vector<vector<int>> results;
	vector<int> result;
	DFS(0, result, results);

	int ans = 0;
	for (auto& r : results)
	{
		if (BFS(board, r))ans++;
	}

	cout << ans;
	return 0;
}