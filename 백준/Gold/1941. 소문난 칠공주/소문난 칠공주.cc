#include <iostream>
#include <queue>
#include <string>
using namespace std;

string seat[5];
int princess[7];
bool isPrincess [5][5];
int ans, cntS;

queue<pair<int, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[5][5];

pair<int, int> Convert1Dto2D(int i)
{
	return { i / 5, i % 5 };
}

//BFS를 활용해 모든 공주가 이웃한지 확인
bool IsAdjacency()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			visited[i][j] = false;
	}

	pair<int, int> pos = Convert1Dto2D(princess[0]);
	visited[pos.first][pos.second] = true;
	q.push(pos);
	cnt++;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;
			if (!isPrincess[nx][ny] || visited[nx][ny])
				continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
			cnt++;
		}
	}
	
	if (cnt == 7)
		return true;
	return false;
}

void func(int cnt, int start)
{
	if (cnt == 7) {
		if (cntS >= 4 && IsAdjacency()) {
			ans++;
		}
		return;
	}
	else {
		for (int i = start; i < 25; i++) {
			pair<int, int> pos = Convert1Dto2D(i);
			if (isPrincess[pos.first][pos.second])
				continue;
			isPrincess[pos.first][pos.second] = true;
			if (seat[pos.first][pos.second] == 'S')
				cntS++;
			princess[cnt] = i;
			
			func(cnt + 1, i + 1);
			
			isPrincess[pos.first][pos.second] = false;
			if (seat[pos.first][pos.second] == 'S')
				cntS--;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> seat[i];
	func(0, 0);
	cout << ans;
	return 0;
}