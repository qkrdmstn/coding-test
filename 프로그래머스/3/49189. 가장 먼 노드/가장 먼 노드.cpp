#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> adj(n+1);
    for(auto &e: edge)
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
        maxDist = max(maxDist, dist[cur]);
        for(auto &nxt: adj[cur])
        {
            if(dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if(maxDist == dist[i]) answer++;
    }
    return answer;
}