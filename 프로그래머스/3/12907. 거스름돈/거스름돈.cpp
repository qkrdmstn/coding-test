#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    // 같은 조합을 중복으로 세지 않도록 동전을 기준으로 먼저 순회합니다.
    for(const auto& coin: money)
    {
        // i원은 (i-coin)원을 만드는 방법에 현재 동전을 더하면 만들 수 있습니다.
        for(int i=coin; i<=n; i++)
            dp[i] += dp[i-coin];
    }
    return dp[n];
}