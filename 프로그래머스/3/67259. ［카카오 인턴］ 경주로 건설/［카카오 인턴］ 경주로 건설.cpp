#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(4, INF)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    
    pq.push({0,0,0,0});
    pq.push({0,0,0,1});
    cost[0][0][0] = cost[0][0][1] = 0;
    while(!pq.empty())
    {
        int curCost, cx, cy, cDir;
        tie(curCost, cx, cy, cDir) = pq.top(); pq.pop();
        if(curCost > cost[cx][cy][cDir]) continue;
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 1) continue;     
            
            int addCost = (dir == cDir) ? 100:600;
            int newCost = curCost + addCost;
            if(newCost < cost[nx][ny][dir])
            {
                cost[nx][ny][dir] = newCost;
                pq.push({newCost, nx, ny, dir});
            }
            
        }
    }
    
    int answer = INF;
    for(int dir=0; dir<4;dir++)
        answer = min(answer, cost[n-1][n-1][dir]);
    return answer;
}