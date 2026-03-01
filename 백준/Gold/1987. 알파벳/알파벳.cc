#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void DFS(int cnt, int x, int y, vector<bool>& visited, vector<vector<char>>& board, int& answer)
{
	answer = max(answer, cnt);

	int r = board.size();
	int c = board[0].size();
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if(visited[board[nx][ny]-'A']) continue;
		visited[board[nx][ny] - 'A'] = true;
		DFS(cnt + 1, nx, ny, visited, board, answer);
		visited[board[nx][ny] - 'A'] = false;

	}
}

int main(void)
{
	int r, c;
	cin >> r >> c;

	vector<vector<char>> board(r, vector<char>(c));
	vector<bool> visited(26, false);
	for (int i = 0; i < r; i++)
	{
		for(int j=0; j<c; j++)
			cin >> board[i][j];
	}
	int answer = 0;
	visited[board[0][0] - 'A'] = true;
	DFS(1, 0, 0, visited, board, answer);
	cout << answer;
	return 0;
}