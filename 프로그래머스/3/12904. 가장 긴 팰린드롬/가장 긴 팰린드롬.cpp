#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s)
{
    int answer = 1;
    
    int len = s.length();
    // dp[st][ed]: st~ed까지의 부분문자열이 팰린드롬인지 확인
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    
    // 길이가 1인 문자열은 모두 팰린드롬 문자열입니다.
    dp[0][0] = true;
    for(int i=1; i<len; i++)
    {
        dp[i][i] = true;
        // 앞뒤가 같으면 팰린드롬 문자열입니다.
        if(s[i-1] == s[i]) {
            dp[i-1][i] = true;
            answer = 2;
        }
    }
    
    for(int diff = 2; diff<len; diff++)
    {
        for(int st = 0; st<len-diff; st++)
        {
            int ed = st + diff;
            // 시작과 끝 문자가 같고, 사이의 부분문자열이 팰린드롬이면 st~ed는 팰린드롬입니다.
            if(s[st] == s[ed] && dp[st+1][ed-1])
            {
                dp[st][ed] = true;
                answer = max(answer, ed-st+1);                
            }
        }
    }
    
    return answer;
}