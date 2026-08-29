#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    // 이미 사용한 동전의 중복을 방지하기 위해 새로운 동전을 하나씩 추가하는 순서로 순회합니다.
    for(const auto& m: money)
    {
        for(int i=m; i<=n; i++)
            dp[i] += dp[i-m];
    }
    return dp[n];
}