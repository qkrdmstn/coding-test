#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));
    for(auto& res: results)
        adj[res[0]][res[1]] = true;
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adj[i][k] && adj[k][j]) adj[i][j] = true;
            }
        }
    }
    
    vector<int> cnt(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            if(adj[i][j])
            {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if(cnt[i] == n-1) answer++;
    }
    return answer;
}