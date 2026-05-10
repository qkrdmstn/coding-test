#include <string>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(auto fare: fares)
    {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    answer = dist[s][a] + dist[s][b];
    for(int k=1; k<=n; k++)
    {
        if(dist[s][k] == INF || dist[k][a] == INF || dist[k][b] == INF) continue;
        answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);
    }
    return answer;
}