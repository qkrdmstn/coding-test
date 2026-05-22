#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    if(n == 1) return sticker[0];
    
    // dp[i] = 스티커가 sitcker[i] 까지 있을 때의 최대 합
    // 원형이기 때문에 첫 번째 스티거를 때는 경우/아닌 경우로 나눠 dp를 구성합니다.
    
    // sticker[0] 를 반드시 뜯어내는 경우 최대 합
    vector<int> dp1(n, 0);
    dp1[0] = dp1[1] = sticker[0];
    for(int i=2; i<n; i++)
        dp1[i] = max(dp1[i-1], dp1[i-2] + sticker[i]);
    
    // sticker[1] 를 반드시 뜯어내는 경우의 최대 합
    vector<int> dp2(n, 0);
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for(int i=2; i<n; i++)
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i]);
    answer = max(dp1[n-2], dp2[n-1]);
    return answer;
}