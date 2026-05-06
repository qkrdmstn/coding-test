#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    
    for(auto& fare: fares)
    {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
    
    for(int k=1; k<=n; k++)
    {
        for(int st=1; st<=n; st++)
        {
            for(int ed=1; ed<=n; ed++)
            {
                if(dist[st][k] + dist[k][ed] < dist[st][ed])
                    dist[st][ed] = dist[st][k] + dist[k][ed];
            }
        }
    }
    
    answer = dist[s][a] + dist[s][b];
    for(int i=1; i<=n; i++)
    {
        if(dist[s][i] == INF || dist[i][a] == INF || dist[i][b] == INF) continue;
        if(dist[s][i] + dist[i][a] + dist[i][b] < answer)
            answer = dist[s][i] + dist[i][a] + dist[i][b];
    }
    return answer;
}