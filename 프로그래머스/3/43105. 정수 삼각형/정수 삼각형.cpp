#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //dp[i][j] : i번째 층의 j번째 수에 도착하는 최댓값
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(),0));
    
    dp[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++)
    {
        for(int j=0; j<triangle[i].size(); j++)
        {
            //dp[i][j] = max(dp[i-1][left], dp[i-1][right])
            //이때 index 범위를 벗어나지 않도록 처리합니다.
            int left = j - 1;
            int right = j;
            int maxSum = 0;
            if(left < 0)
                maxSum = dp[i-1][right];
            else if(right >= triangle[i].size())
                maxSum = dp[i-1][left];
            else 
                maxSum = max(dp[i-1][left], dp[i-1][right]);
            dp[i][j] = triangle[i][j] + maxSum;
        }
    }
    //마지막 층을 순회하며 최댓값을 선택합니다.
    for(int i=0; i<triangle.size(); i++)
        answer = max(dp[triangle.size()-1][i], answer);
    return answer;
}