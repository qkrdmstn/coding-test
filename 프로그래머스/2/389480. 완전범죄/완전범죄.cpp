#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    int itemCnt = info.size();
    vector<vector<int>> dp(itemCnt + 1, vector<int>(m, 0));
    
    for(int i=1; i<=itemCnt; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a = info[i-1][0];
            int b = info[i-1][1];
            
            // b의 흔적을 더 남길 수 없다면, a가 훔칩니다.
            if(j < b)
                dp[i][j] = dp[i-1][j] + a;
            // b가 훔치는 것과, a가 훔치는 것 중 a의 남는 흔적이 최소인 것을 선택합니다.
            else
                dp[i][j] = min(dp[i-1][j-b], dp[i-1][j] + a);
        }
    }
    if(dp[itemCnt][m-1] >= n) return -1;
    return dp[itemCnt][m-1];
}