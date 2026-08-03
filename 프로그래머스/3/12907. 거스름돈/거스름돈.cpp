#include <string>
#include <vector>

using namespace std;

const int PRIME = 1'000'000'007;
int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(const auto& m : money)
    {
        for(int i=m; i<=n; i++)
            dp[i] += dp[i-m];
    }
    return dp[n];
}