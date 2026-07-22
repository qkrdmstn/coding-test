#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    int sz = sticker.size();
    if(sz == 1) return sticker[0];
    
    
    vector<int> dp1(sz, 0);
    dp1[0] = dp1[1] = sticker[0];
    for(int i=2; i<sz-1; i++)
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);
    
    vector<int> dp2(sz, 0);
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for(int i=2; i<sz; i++)
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    return max(dp1[sz-2], dp2[sz-1]);
}