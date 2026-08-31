#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    int num = info.size();
    vector<vector<int>> dp(num+1, vector<int>(m, 0));

    // dp[i][m]: 물건이 i개, B가 남길 수 있는 흔적이 m개일 때 A도둑이 남긴 흔적의 최솟값
    for(int i=1; i<=num; i++)
    {
        for(int j=0; j<m; j++)
        {
            int itemIdx = i-1;
            
            // B의 흔적이 m 이상이 되어 훔치지 못하는 경우 A의 흔적을 남깁니다.
            if(j < info[itemIdx][1])
                dp[i][j] = dp[i-1][j] + info[itemIdx][0];
            // 훔칠 수 있는 경우, B가 훔치는 경우와 A가 훔치는 경우 중 A의 흔적이 적게 남는 것을 택합니다.
            else
                dp[i][j] = min(dp[i-1][j-info[itemIdx][1]], dp[i-1][j] + info[itemIdx][0]);
        }
    }
    
    if(dp[num][m-1] >= n) return -1;
    return dp[num][m-1];
}