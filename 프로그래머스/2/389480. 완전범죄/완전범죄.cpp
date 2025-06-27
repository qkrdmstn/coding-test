#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    vector<vector<int>> dp = vector<vector<int>>(info.size() + 1, vector<int>(m));
    
    for(int i=0; i<info.size(); i++){
        answer += info[i][0];
        for(int j=0; j<m; j++){
            dp[i+1][j] = dp[i][j];
            if(j>=info[i][1])
                dp[i+1][j] = max(dp[i][j], dp[i][j-info[i][1]] + info[i][0]);
        }
    }
    
    answer -= dp[info.size()][m-1];
    if(answer >= n) answer = -1;
    return answer;
}