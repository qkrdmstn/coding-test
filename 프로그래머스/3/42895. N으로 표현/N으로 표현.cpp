#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    vector<unordered_set<int>> dp(9, unordered_set<int>());
    int num = N;
    for(int i=1; i<=8; i++)
    {
        dp[i].insert(num);
        num = num * 10 + N;
    }
    
    for(int i=2; i<=8; i++)
    {
        for(int j=1; j<i; j++)
        {
            for(auto d: dp[j])
            {
                for(auto p: dp[i-j])
                {
                    dp[i].insert(d+p);
                    dp[i].insert(d-p);
                    dp[i].insert(d*p);
                    if(p != 0) dp[i].insert(d/p);
                }
            }
            if(dp[i].find(number) != dp[i].end()) return i;
        }
    }
    return -1;
}