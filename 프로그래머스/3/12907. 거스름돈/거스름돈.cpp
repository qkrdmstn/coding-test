#include <string>
#include <vector>

using namespace std;
const int PRIME = 1'000'000'007;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int& coin: money)
    {
        for(int i=coin; i<=n; i++)
            dp[i] = (dp[i] + dp[i-coin]) % PRIME;
    }
    return dp[n];
}