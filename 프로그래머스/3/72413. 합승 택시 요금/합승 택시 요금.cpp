#include <string>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
    for(const auto& f: fares)
    {
        if(f[2] < dist[f[0]][f[1]])
        {
            dist[f[0]][f[1]] = f[2];
            dist[f[1]][f[0]] = f[2];
        }
    }
    
    // 플로이드 워셜 알고리즘을 통해 모든 경로의 최단 거리를 탐색합니다.
    for(int mid=1; mid<=n; mid++)
    {
        for(int st=1; st<=n; st++)
        {
            for(int ed=1; ed<=n; ed++)
            {
                if(dist[st][mid] + dist[mid][ed] < dist[st][ed])
                    dist[st][ed] = dist[st][mid] + dist[mid][ed];
            }
        }
    }
    
    // 합승을 하지 않는 방법을 초기값으로 설정합니다.
    answer = dist[s][a] + dist[s][b];

    // mid 지점까지 합승하는 방법을 탐색합니다.
    for(int mid=1; mid<=n; mid++)
    {
        // mid 지점을 거쳐가는 경로가 없는 경우 skip 합니다.
        if(dist[s][mid] == INF || dist[mid][a] == INF || dist[mid][b] == INF) continue;
        int d = dist[s][mid] + dist[mid][a] + dist[mid][b];
        answer = min(d, answer);
    }
    return answer;
}