#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> board(n + 1, vector<int>());
    for(int i=0; i<edge.size(); i++)
    {
        board[edge[i][0]].push_back(edge[i][1]);
        board[edge[i][1]].push_back(edge[i][0]);
    }
    
    //BFS
    int maxDist = -1;
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        maxDist = max(dist[cur], maxDist);
        for(auto nxt: board[cur])
        {
            if(dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    
    for(auto d: dist)
    {
        if(d == maxDist) answer++;
    }
    return answer;
}