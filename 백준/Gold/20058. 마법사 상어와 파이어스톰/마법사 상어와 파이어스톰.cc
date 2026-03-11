#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void Rotate(vector<vector<int>>& board, int gridSize, int L)
{
	int len = 1 << L;
	vector<vector<int>> nxtBoard(gridSize, vector<int>(gridSize));

	for (int r = 0; r < gridSize; r += len)
	{
		for (int c = 0; c < gridSize; c += len)
		{
			for (int i = 0; i < len; i++)
			{
				for(int j=0; j<len; j++)
					nxtBoard[r+j][c+len-1-i] = board[r+i][c+j];
			}
		}
	}
	board = nxtBoard;
}

void MeltIce(vector<vector<int>>& board, int gridSize)
{
	vector<pair<int, int>> list;

	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (board[i][j] == 0) continue;
			
			// 인접한 얼음 개수 세기.
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= gridSize || ny < 0 || ny >= gridSize) continue;
				if (board[nx][ny] == 0) continue;
				cnt++;
			}
			
			if(cnt < 3) list.push_back({i, j});
		}
	}
	for(auto pos: list)
		board[pos.first][pos.second]--;
}

int main(void)
{
	int N, Q;
	cin >> N >> Q;
	int gridSize = 1 << N;
	
	vector<vector<int>> board(gridSize, vector<int>(gridSize));
	for (int i = 0; i < gridSize; i++)
	{
		for(int j=0; j<gridSize; j++)
			cin >> board[i][j];
	}

	while(Q--)
	{
		int L;
		cin >> L;
		
		//L==0은 회전X
		if (L > 0)
			Rotate(board, gridSize, L);
		MeltIce(board, gridSize);
	}

	//각 얼음 덩어리별로 그룹화한다.
	int sum = 0;
	int maxGroupSize = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(gridSize, vector<bool>(gridSize, false));
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if(board[i][j] == 0 || visited[i][j]) continue;
			q.push({i, j});
			visited[i][j] = true;
			int curGroupSize = 0;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				
				sum += board[cur.first][cur.second];
				curGroupSize++;

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= gridSize || ny < 0 || ny >= gridSize) continue;
					if (board[nx][ny] == 0 || visited[nx][ny]) continue;
					q.push({nx, ny});
					visited[nx][ny] = true;;
				}
			}

			maxGroupSize = max(curGroupSize, maxGroupSize);
		}
	}


	cout << sum << "\n";
	cout << maxGroupSize << "\n";
	return 0;
}