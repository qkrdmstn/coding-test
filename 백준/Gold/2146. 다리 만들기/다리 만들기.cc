#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
int map[301][301];
int dist[301][301] = {};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int islandNum = 2; //섬 번호는 2부터 시작
int minDist = 10000000;

void InitDist()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
}

void TaggedIslandEdge() //섬 가장자리를 표시
{
    InitDist();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && dist[i][j] == -1) {
                dist[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({ i, j });

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (map[nx][ny] == 0) {
                            map[nx][ny] = islandNum;
                            continue;
                        }
                        if (map[nx][ny] != 1 && map[nx][ny] != 0 && map[nx][ny] != islandNum)
                            minDist = 1;
                        if (dist[nx][ny] != -1 || map[nx][ny] != 1)
                            continue;

                        q.push({ nx, ny });
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    }
                }
                islandNum++;
            }
        }
    }

    //cout << "\n";
    //for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //      cout << setw(3) << map[i][j] << " ";
    //   }
    //   cout << "\n";
    //}
    //cout << "\n";
}

int GetShortestDist(int islandNum) //현재 섬에서 다른 섬까지의 최단거리를 반환
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) { //현재 섬의 모든 가장자리에서 동시에 출발
        for (int j = 0; j < n; j++) {
            if (map[i][j] == islandNum) {
                dist[i][j] = 1;
                q.push({ i, j });
            }
            else
                dist[i][j] = -1;
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            // 다른 섬의 가장자리에 도착했을 경우 반환
            if (map[nx][ny] > 1 && map[nx][ny] != islandNum) {

                //cout << "\n";
                //cout << "\n";
                //for (int i = 0; i < n; i++) {
                //   for (int j = 0; j < n; j++) {
                //      cout << setw(3)<< dist[i][j] << " ";
                //   }
                //   cout << "\n";
                //}
                return dist[cur.first][cur.second] + 1;
            }
            //이미 방문했거나, 육지일 경우 반환
            if (dist[nx][ny] != -1 || map[nx][ny] == 1)
                continue;

            q.push({ nx, ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    return 100000;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    TaggedIslandEdge();
    for (int num = 2; num < islandNum - 1; num++) {
        int distance = GetShortestDist(num);
        if (distance < minDist) {
            minDist = distance;
        }
    }
    cout << minDist;
    return 0;
}