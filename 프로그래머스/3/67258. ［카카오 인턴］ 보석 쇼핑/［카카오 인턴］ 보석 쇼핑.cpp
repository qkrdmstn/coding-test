#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    int n = gems.size();
    
    // 전체 보석의 종류를 set을 활용해 계산합니다.
    int gemsKind = unordered_set<string>(gems.begin(), gems.end()).size();

    unordered_map<string, int> gemsCount;
    int st = 0;
    int minLen = n+1;
    gemsCount[gems[0]] = 1;
    
    if(gemsCount.size() == gemsKind)
        return {1,1};
    // 슬라이딩 윈도우
    for(int ed=1; ed<n; ed++)
    {
        gemsCount[gems[ed]]++;
        // 각 종류의 보석이 1개만 남도록 윈도우의 st 지점을 수정합니다.
        while(gemsCount[gems[st]] > 1)
        {
            gemsCount[gems[st]]--;
            st++;
        }
        
        // map에 기록된 보석의 종류가 전체 종류와 동일하면 조건 만족
        if(gemsCount.size() == gemsKind)
        {
            int len = ed- st;
            if(len < minLen)
            {
                minLen = len;
                answer = {st+1, ed+1};
            }
        }
    }
    return answer;
}