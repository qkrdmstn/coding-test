#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> adj(n+1);
    for(const auto& e: edge)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    vector<int> dist(n+1, -1);
    q.push(1);
    dist[1] = 0;
    
    int maxDist = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        maxDist = max(dist[cur], maxDist);
        for(const auto& nxt: adj[cur])
        {
            if(dist[nxt]>=0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    for(const int& d: dist)
    {
        if(d == maxDist) answer++;
    }
    return answer;
}