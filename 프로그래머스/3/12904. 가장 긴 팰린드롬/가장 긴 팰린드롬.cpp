#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int len = s.length();
    
    // dp[st][ed]: st부터 ed까지의 문자열이 팰린드롬인지 나타낸다.
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    
    for(int i=0; i<len; i++)
    {
        dp[i][i] = true;
        if(i+1 < len && s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            answer = 2;
        }
    }
    
    for(int diff=2; diff<len; diff++)
    {
        for(int st=0; st<len-diff; st++)
        {
            int ed = st + diff;
            // [st, ed]는 [st+1, ed-1]가 팰린드롬이고, st와 ed번째 문자가 같으면 팰린드롬이다.
            if(s[st] == s[ed] && dp[st+1][ed-1])
            {
                dp[st][ed] = true;
                answer = max(diff+1, answer);
            }
        }
    }
    return answer;
}