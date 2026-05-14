#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    // dp[i][j]: b가 남길 수 있는 흔적 i개, 물건이 j개 있을 때 
    // A의 흔적 최소 값
    vector<vector<int>> dp(m, vector<int>(info.size() + 1, 0));
    
    for(int i=0; i<m; i++)
        dp[i][0] = 0;
    
    for(int i=1; i<=info.size(); i++)
    {
        for(int j=0; j<m; j++)
        {
            int aInfo = info[i-1][0];
            int bInfo = info[i-1][1];
            // B가 물건을 훔칠 수 없는 경우
            if(j < bInfo) 
                dp[j][i] = dp[j][i-1] + aInfo; // A가 물건을 훔칩니다.
            // B가 물건을 훔칠 수 있는 경우, B가 훔치는 것과 A가 훔치는 것 중 더 최소인 것을 선택합니다.
            else
                dp[j][i] = min(dp[j-bInfo][i-1], dp[j][i-1] + aInfo);
        }
    }
    answer = dp[m-1][info.size()];
    if(answer >= n) answer = -1;
    return answer;
}