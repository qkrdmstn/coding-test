#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> adj(N+1);
    for(const auto& r: road)
    {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }
    
    
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq; // {비용, 도착 노드}
    vector<int> dist(N+1, INF);
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if(dist[curNode] != curCost) continue;
        for(auto& nxt: adj[curNode])
        {
            int nxtNode = nxt.first;
            int nxtCost = nxt.second;
            if(dist[curNode] + nxtCost < dist[nxtNode])
            {
                dist[nxtNode] = dist[curNode] + nxtCost;
                pq.push({dist[nxtNode], nxtNode});
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        if(dist[i] <= K) answer++;        
    }
    return answer;
}