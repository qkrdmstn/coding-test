#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    //dp[i][j]: (i,j)에 도착하는 경우의 수
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> isPuddle(m + 1, vector<bool>(n + 1,false));

    //물에 잠긴 위치를 bool로 표시합니다.
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
            //물에 잠겼거나 시작 위치는 건너뜁니다.
            if(isPuddle[i][j] || (i==1 && j == 1)) continue;
            
            //dp[i][j] = dp[i-1][j] + dp[i][j-1]입니다.
            //즉, 윗칸과 왼쪽칸에 도달하는 경우의 수를 더합니다.
            //이때 범위에 대한 예외처리를 진행합니다
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