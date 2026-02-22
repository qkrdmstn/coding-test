#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    
    //첫 번째 집을 훔치는 경우와 훔치지 않는 경우를 나눕니다.
    //dp[i]: i번째 집까지 훔쳤을 때 돈의 최댓값
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);

    //1.첫 번째 집을 훔치는 경우, 2번째 집은 훔치지 못하기 때문에 초기값을 초기화합니다.
    dp1[0] = money[0];
    dp1[1] = money[0];
    //첫 번째 집을 훔치면 바로 옆의 마지막 집은 훔치지 못하기 때문에 n-1번째까지만 순회합니다.
    for(int i=2; i<n-1; i++)
    {
        //i번째까지의 최댓값은 i-1번째 집을 훔치고 i번째를 훔치지 않는 경우와
        //i-2번째 전의 집과 i번째 집을 훔치는 경우 중 큰 값으로 설정합니다.
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }
    
    //2번째 집을 훔치는 경우 첫 번째 집까지는 훔친 돈이 없기 때문에 0으로 설정합니다.
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2; i<n; i++)
    {
        //위와 동일합니다.
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    //각 경우 마지막 집까지 도달했을 때를 기준으로 더 큰값이 최댓값 입니다.
    answer = max(dp1[n-2], dp2[n-1]);
    return answer;
}