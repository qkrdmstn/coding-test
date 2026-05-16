#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    int answer = 1;
    for(int i=0; i<n; i++)
        dp[i][i] = true;
    
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            answer = max(answer, 2);  
        }
    }
    
    for(int diff=2; diff<n; diff++)
    {
        for(int st=0; st<n-diff; st++)
        {
            int ed = st + diff;
            if(s[st] == s[ed] && dp[st+1][ed-1])
            {
                answer = max(diff+1, answer);
                dp[st][ed] = true;
            }
        }
    }
    return answer;
}