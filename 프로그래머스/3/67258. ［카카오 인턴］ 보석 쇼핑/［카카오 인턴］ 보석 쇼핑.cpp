#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

const int INF = 100'001;
vector<int> solution(vector<string> gems) {
    vector<int> answer(2, -1);
    
    int n = gems.size();
    int kindOfGems = unordered_set<string>(gems.begin(), gems.end()).size();

    // (투포인터) [st, ed] 구간에 존재하는 보석들의 개수를 종류별로 셉니다. 
    unordered_map<string, int> rangeGems;
    int minLen = INF;
    int st = 0;
    for(int ed=0; ed<n; ed++)
    {
        rangeGems[gems[ed]]++;
        
        // 모든 종류의 보석이 구간에 포함돼있으면 앞에서부터 구간을 줄입니다.
        while(rangeGems.size() == kindOfGems)
        {
            // 현재 구간이 최소 길이라면 답을 업데이트 합니다.
            int curLen = ed - st;
            if(curLen < minLen)
            {
                minLen = curLen;
                answer = {st+1, ed+1};
            }
            
            // 앞 구간 줄이기
            rangeGems[gems[st]]--;
            if(rangeGems[gems[st]] <= 0)
                rangeGems.erase(gems[st]);
            st++;
        }
    }
    return answer;
}