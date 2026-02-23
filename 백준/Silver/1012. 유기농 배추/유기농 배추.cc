#include<iostream>
#include<queue>
using namespace std;

int t;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        queue<pair<int, int>> q;
        int map[51][51] = {};
        bool visited[51][51] = {};

        int m, n, k;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    q.push({ i,j });
                    visited[i][j] = true;
                    cnt++;
                    
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
                            if (visited[nx][ny] || map[nx][ny] != 1)
                                continue;
                            q.push({ nx, ny });
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}