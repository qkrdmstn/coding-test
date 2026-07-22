#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int len = money.size();
    
    // 원형 배치를 일렬로 나열한 뒤, 첫 번째 집을 터는 경우와 두 번째 집을 터는 경우를 나누어 계산합니다.
    // 각 경우 dp를 활용해 현재 집을 털지, 털지 않을지를 계산합니다.
    vector<int> dp1(len, 0);
    dp1[0] = dp1[1] = money[0];
    // 첫 번쨰 집을 터는 경우, 마지막 집을 털지 못하기 때문에 len-2번째 집까지 순회합니다.
    for(int i=2; i<len-1; i++)
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    
    vector<int> dp2(len, 0);
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2; i<len; i++)
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
        
    return max(dp1[len-2], dp2[len-1]);
}