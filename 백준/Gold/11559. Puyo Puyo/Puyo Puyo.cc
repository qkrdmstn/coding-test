#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string map[12];
int ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Down(int col) //각 색깔의 뿌요를 중력에 의해 떨어뜨리기
{
	char temp[12];
	fill(temp, temp + 12, '.');
	int point = 11;

	for (int i = 11; i >= 0; i--) {
		if (map[i][col] == '.')
			continue;
		temp[point--] = map[i][col];
	}
	for (int i = 11; i >= 0; i--) {
		map[i][col] = temp[i];
	}
}

void Puyo() //BFS를 활용해서 각각의 뿌요가 4개 이상 연결돼있는지 확인
{
	bool isConnect = false;
	bool visited[12][6] = {};

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.' || visited[i][j] )
				continue;
			vector<pair<int, int>> v; //방문한 뿌요를 저장하는 vector
			queue<pair<int, int>> q;

			q.push({ i, j });
			v.push_back({ i, j });
			visited[i][j] = true;
			char curColor = map[i][j];

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					
					if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
						continue;
					if (visited[nx][ny] || curColor != map[nx][ny] || map[nx][ny] == '.')
						continue;

					visited[nx][ny] = true;
					q.push({ nx, ny });
					v.push_back({ nx, ny });
				}
			}

			if (v.size() >= 4) { //4개 이상 연결돼있으면 지우기
				for (auto pos: v) {
					map[pos.first][pos.second] = '.';
					isConnect = true;
				}
			}
		}
	}
	
	if (isConnect) { //한 번이라도 연쇄가 일어났으면 Down 및 다시 뿌요 호출
		ans++;
		for(int i=0; i<6; i++)
			Down(i);
		Puyo();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 12; i++) {
			cin >> map[i];
	}
	Puyo();
	cout << ans;
	return 0;
}