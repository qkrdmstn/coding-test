#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    
    // 스티커의 개수가 1개인 경우 해당 스티커의 값이 최대입니다. 
    int n = money.size();
    
    // 집이 원형으로 연결돼있고, 인접한 집을 털 수 없기 때문에 두 경우로 나눠서 계산합니다.
    // 각각의 경우 (i-2번째까지의 합 + 현재 집의 돈)과 (i-1번째까지의 합) 중 더 큰 값을 기록합니다.
    
    // 첫 번째 집을 훔치는 경우, 마지막 집과 두 번째 집은 털지 못합니다.
    // 따라서, dp[1] = money[0]가 되고, n-2 번째까지만 계산합니다.
    vector<int> dp1(n, 0);
    dp1[0] = dp1[1] = money[0];
    for(int i=2; i<n-1; i++)
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);

    // 두 번째 집을 터는 경우, 첫 번째 집은 털지 못합니다.
    // 따라서, dp[0] = 0이 됩니다.
    vector<int> dp2(n, 0);
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2; i<n; i++)
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    
    // 두 경우에 대한 누적합 중 더 큰 값을 반환합니다.
    return max(dp1[n-2], dp2[n-1]);
}