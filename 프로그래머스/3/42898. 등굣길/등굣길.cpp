#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> isPuddle(m + 1, vector<bool>(n + 1,false));

    for(auto p: puddles)
    {
        isPuddle[p[0]][p[1]] = true;
        dp[p[0]][p[1]] = 0;
    }
    
    dp[1][1] = 1;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(isPuddle[i][j] || (i==1 && j == 1)) continue;
            int up = 0, left = 0;
            if(i-1 >= 1)
                up = dp[i-1][j];
            if(j-1 >= 1)
                left = dp[i][j-1];
            dp[i][j] =  (up + left) % 1000000007;
        }
    }
    
    return dp[m][n];
}