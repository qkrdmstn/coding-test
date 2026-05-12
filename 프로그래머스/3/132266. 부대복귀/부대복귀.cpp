#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> adj(n+1);
    for(auto& road: roads)
    {
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }
    
    queue<int> q;
    vector<int> dist(n+1, -1);
    q.push(destination);
    dist[destination] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int& nxt: adj[cur])
        {
            if(dist[nxt] >= 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    for(auto& source: sources)
    {
        answer.push_back(dist[source]);
    }
    return answer;
}