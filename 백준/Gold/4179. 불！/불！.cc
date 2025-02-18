#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
string map[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
            if (map[i][j] == 'F') {
                q1.push({ i,j });
                dist1[i][j] = 0;
            }
            else if (map[i][j] == 'J') {
                q2.push({ i,j });
                dist2[i][j] = 0;
            }
        }
    }

    //불 BFS
    while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist1[nx][ny] != -1 || map[nx][ny] == '#')
                continue;

            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q1.push({ nx, ny });
        }
    }

    //지훈 BFS
    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //탈출
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if (dist2[nx][ny] != -1 || map[nx][ny] == '#')
                continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1)
                continue;

            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push({ nx, ny });
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}