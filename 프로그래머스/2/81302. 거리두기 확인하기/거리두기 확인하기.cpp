#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool BFS(vector<string>& place)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(place[i][j] != 'P') continue;
            
            queue<pair<int, int>> q;
            vector<vector<int>> dist(5, vector<int>(5, -1));
            q.push({i, j});
            dist[i][j] = 0;
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                if(place[cur.first][cur.second] == 'P' && dist[cur.first][cur.second] > 0 &&dist[cur.first][cur.second] <= 2)
                    return false;
                if(dist[cur.first][cur.second] > 2) break;
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if(dist[nx][ny] >= 0 || place[nx][ny] == 'X') continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& place: places)
        answer.push_back(BFS(place));
    return answer;
}