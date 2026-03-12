#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct Token {
	int x, y, dir;
};

int InvDir(int dir)
{
	if(dir==0) dir = 1;
	else if(dir == 1) dir = 0;
	else if(dir == 2) dir = 3;
	else if(dir == 3) dir = 2;
	return dir;
}

int main(void)
{
	int N, K;
	int board[15][15];
	vector<Token> tokens;
	vector<int> state[15][15];

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for(int j=0; j<N; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < K; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		tokens.push_back({x-1,y-1,d-1});
		state[x-1][y-1].push_back(i);
	}

	int turn = 1;
	while (turn <= 1000)
	{
		for (int i = 0; i < K; i++)
		{
			int x = tokens[i].x;
			int y = tokens[i].y;
			int dir = tokens[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//파랑이거나 맵 밖이면 방향 뒤집기
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2)
			{
				tokens[i].dir = InvDir(tokens[i].dir);
				dir = tokens[i].dir;
				nx = x + dx[dir];
				ny = y + dy[dir];
				//뒤집고도 밖이거나 파랑이면 건너뛰기
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 2)
					continue;
			}

			//현재 위치의 말 정보 가져와서 몇 번째 높이인지 찾기
			vector<int>& curStack = state[x][y];
			int height = 0;
			for (int h = 0; h < curStack.size(); h++)
			{
				if (curStack[h] == i)
				{
					height = h;
					break;
				}
			}

			//현재 토큰부터 제일 위 토큰까지 복사
			vector<int> movingTokens(curStack.begin() + height, curStack.end());
			//다음 위치가 빨강이라면 뒤집기
			if(board[nx][ny] == 1)
				reverse(movingTokens.begin(), movingTokens.end());

			//토큰 위치 옮기기
			for (int t : movingTokens)
			{
				state[nx][ny].push_back(t);
				tokens[t].x = nx;
				tokens[t].y = ny;
			}

			//기존 위치의 스택 지우기
			curStack.erase(curStack.begin() + height, curStack.end());


			if (state[nx][ny].size() >= 4)
			{
				cout << turn << "\n";
				return 0;
			}
		}
		turn++;
	}
	cout << -1 << "\n";
	return 0;
}