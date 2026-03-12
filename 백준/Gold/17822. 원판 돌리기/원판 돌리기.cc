#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void Rotate(deque<int>& dq, int d, int k)
{
	while (k--)
	{
		//시계
		if (d == 0)
		{
			dq.push_front(dq.back());
			dq.pop_back();
		}
		//반시계
		else
		{
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
}

void Remove(vector<deque<int>>& board, int N, int M)
{
	int sum = 0;
	int cnt = 0;
	vector<pair<int, int>> remove;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(board[i][j] == 0) continue;
			sum += board[i][j];
			cnt++;

			int curNum = board[i][j];
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 1 || nx > N) continue;
				//원형 인덱스 처리를 진행합니다.
				if (ny < 0 || ny >= M) ny = (ny + M) % M;

				if (board[nx][ny] == curNum)
				{
					remove.push_back({i, j});
					break;
				}
			}
		}
	}

	if (remove.empty())
	{
		float avg = (float)sum/cnt;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 0) continue;
				if(board[i][j] < avg)
					board[i][j]++;
				else if(board[i][j] > avg)
					board[i][j]--;
			}
		}
	}
	else
	{
		for (auto& r : remove)
			board[r.first][r.second] = 0;
	}
}

int main(void)
{
	int N, M, T;
	cin >> N >> M >> T;
	
	vector<deque<int>> board(N + 1, deque<int>(M, 0));
	for (int i = 1; i <= N; i++)
	{
		for(int j=0; j<M; j++)
			cin >> board[i][j];
	}

	while (T--)
	{
		int x, d, k;
		cin >> x >> d >> k;
		for(int i=x; i<=N; i+=x)
			Rotate(board[i], d, k);
		Remove(board, N, M);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
			ans += board[i][j];
	}
	cout << ans;
}