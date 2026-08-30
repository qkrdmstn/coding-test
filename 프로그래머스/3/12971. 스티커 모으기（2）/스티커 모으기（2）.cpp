#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    // 스티커의 개수가 1개인 경우 해당 스티커의 값이 최대입니다. 
    int n = sticker.size();
    if(n == 1) return sticker[0];
    
    // 스티커가 원형으로 연결돼있고, 인접한 스티커가 찢어지기 때문에 두 경우로 나눠서 계산합니다.
    // 각각의 경우 (i-2번째까지의 합 + 현재 스티커 값)과 (i-1번째까지의 합) 중 더 큰 값을 기록합니다.
    
    // 첫 번째 스티커를 떼는 경우, 마지막 스티커와 두 번째 스티커는 찢어집니다.
    // 따라서, dp[1] = sticker[0]가 되고, n-2 번째까지만 계산합니다.
    vector<int> dp1(n, 0);
    dp1[0] = dp1[1] = sticker[0];
    for(int i=2; i<n-1; i++)
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);

    // 두 번째 스티커를 떼는 경우, 첫 번째 스티커는 찢어집니다.
    // 따라서, dp[0] = 0이 됩니다.
    vector<int> dp2(n, 0);
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for(int i=2; i<n; i++)
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    
    // 두 경우에 대한 누적합 중 더 큰 값을 반환합니다.
    return max(dp1[n-2], dp2[n-1]);
}