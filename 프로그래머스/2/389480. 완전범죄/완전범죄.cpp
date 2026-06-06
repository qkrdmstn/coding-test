#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    // dp[i][j]: 물건이 i개 있고 b가 남길 수 있는 흔적이 j개 있을 때
    // 남길 수 있는 A의 흔적 최소값
    vector<vector<int>> dp(info.size()+1, vector<int>(m, 0));
    
    for(int i=1; i<=info.size(); i++)
    {
        for(int j=0; j<m; j++)
        {
            int a = info[i-1][0];
            int b = info[i-1][1];
            
            if(j < b) dp[i][j] = dp[i-1][j] + a;
            else dp[i][j] = min(dp[i-1][j-b], dp[i-1][j] + a);
        }
    }
    answer = dp[info.size()][m-1];
    if(answer >= n) return -1;
    return answer;
}