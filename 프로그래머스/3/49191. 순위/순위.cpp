#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, 0));
    for(auto &r: results)
        dist[r[0]][r[1]] = 1;

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
            }
        }
    }
    
    vector<int> cnt(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cnt[i] += dist[i][j];
            cnt[j] += dist[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(cnt[i] == n-1) answer++;
    }
    return answer;
}