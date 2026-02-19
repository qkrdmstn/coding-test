#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;
    
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nxtX = curX + dx[i];
            int nxtY = curY + dy[i];
            if(nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= m) continue;
            if(maps[nxtX][nxtY] == 0 || dist[nxtX][nxtY] >= 0) continue;
            q.push({nxtX, nxtY});
            dist[nxtX][nxtY] = dist[curX][curY] + 1;
        }
    }
    return dist[n - 1][m - 1];
}