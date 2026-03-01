#include <iostream>
#include <vector>
using namespace std;

bool IsPossible(int x, int y, vector<vector<int>>& board)
{
	int n = board.size();
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	if (board[x][y] != 0) return false;
	return true;
}

bool Right(int state, int x, int y, vector<vector<int>>& board)
{
	if(state == 1) return false;
	int nx = x;
	int ny = y + 1;

	return IsPossible(nx, ny, board);
}

bool Down(int state, int x, int y, vector<vector<int>>& board)
{
	if(state == 0) return false;
	int nx = x + 1;
	int ny = y;
	return IsPossible(nx, ny, board);
}

bool RightDown(int x, int y, vector<vector<int>>& board)
{
	int dx[3] = {0,1,1};
	int dy[3] = {1,1,0};
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!IsPossible(nx, ny, board)) return false;
	}
	return true;
}

void DFS(int state, int x, int y, vector<vector<int>>& board, int& answer)
{
	if (x == board.size() - 1 && y == board.size() - 1)
	{
		answer++;
		return;
	}
	if(Right(state, x, y, board)) DFS(0, x, y+1, board, answer);
	if(Down(state, x, y, board)) DFS(1, x+1, y, board, answer);
	if(RightDown(x, y, board)) DFS(2, x+1, y+1, board, answer);
}

int main(void)
{
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	int answer = 0;
	DFS(0, 0, 1, board, answer);
	cout << answer;
	return 0;
}