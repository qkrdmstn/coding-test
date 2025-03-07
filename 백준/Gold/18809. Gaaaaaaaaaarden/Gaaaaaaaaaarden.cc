#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int g, r;
int map[50][50];

int totalGroundCnt;
pair<int, int> groundPos[10];
int arr[10];
int comb[10];
bool isUsed[10];

int dx[4] = { 0,0, -1, 1 };
int dy[4] = { 1,-1,0,0 };
int ans;

int BFS()
{
	queue<pair <int, int>> q;
	pair<int, int> dist[50][50];
	int flowerCnt = 0;

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, make_pair(-1, 0));
	}

	//뿌릴 배양액의 색과 위치를 큐에 push
	for (int i = 0; i < totalGroundCnt; i++) {
		if (arr[i] != 0) {
			q.push(groundPos[i]);
			dist[groundPos[i].first][groundPos[i].second] = { 0, arr[i] };
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		int curDist = dist[cur.first][cur.second].first;
		int curState = dist[cur.first][cur.second].second;
		q.pop();

		//현재 땅에 꽃이 핌.
		if (curState == 3)
			continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == 0 )
				continue;

			//땅에 아무것도 없다면,
			if (dist[nx][ny].second == 0) {
				q.push({ nx, ny });
				dist[nx][ny] = { curDist + 1, curState };
			}
			//현재 땅에 green 배양액이 있음
			else if (dist[nx][ny].second == 1) {
				//지금 퍼지는 배양액이 red이고, 이미 있는 green 배양액과 거리가 같다면,
				if (curState == 2 && dist[nx][ny].first == curDist + 1) {
					flowerCnt++;
					dist[nx][ny].second = 3;
				}
			}
			//현재 땅에 red 배양액이 있음
			else if (dist[nx][ny].second == 2) {
				//지금 퍼지는 배양액이 green이고, 이미 있는 red 배양액과 거리가 같다면,
				if (curState == 1 && dist[nx][ny].first == curDist + 1) {
					flowerCnt++;
					dist[nx][ny].second = 3;
				}
			}
		}
	}

	return flowerCnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				groundPos[totalGroundCnt] = { i, j };
				totalGroundCnt++;
			}
		}
	}

	for (int i = 0; i < totalGroundCnt; i++) {
		if (i < totalGroundCnt - (g + r))
			arr[i] = 0;
		else if (i < totalGroundCnt - r)
			arr[i] = 1;
		else
			arr[i] = 2;
	}

	do {
		ans = max(ans, BFS());
	} while (next_permutation(arr, arr + totalGroundCnt));
	cout << ans;

	/*
	중요!!
	1. 백트래킹(DFS)를 활용해서 배양액을 뿌릴 수 있는 땅을 기준으로 중복 없는 순열을 만들려 했으나, 실패!
	-> STL next_permutation 함수는 기본적으로 중복 없는 순열을 반환하기 때문에 이를 기반으로 경우의 수를 따짐.
	
	2. 이후, BFS를 활용해서 두 색깔의 배양액을 기준으로 BFS를 수행함. 
	*/
	return 0;
}