#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

void DFS(int idx, string& order, int c, string& comb, unordered_map<string, int>& m)
{
    if(comb.length() == c)
    {
        //현재 조합이 몇 번 나왔는지 count 한다.
        m[comb]++;
        return;
    }
    
    for(int i=idx; i<order.length(); i++)
    {
        comb += order[i];
        DFS(i + 1, order, c, comb, m);
        comb.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& order: orders)
        sort(order.begin(), order.end());
    
    //코스를 이루는 단품 메뉴의 개수를 순회
    for(auto &c: course)
    {
        unordered_map<string, int> m;
        string comb;
        
        //각 오더에서 현재 코스에 맞는 단품 메뉴 개수를 뽑는 조합 계산
        for(auto& order: orders)
            DFS(0, order, c, comb, m);
        
        //각 조합의 개수를 벡터로 복사
        vector<pair<int, string>> res;
        for(auto &r: m)
            res.push_back({r.second, r.first});
        
        if(!res.empty())
        {
            sort(res.begin(), res.end(), greater<pair<int, string>>());
            int maxCnt = res[0].first;
            int idx = 0;
            while(idx < res.size() && res[idx].first >= 2 && maxCnt == res[idx].first)
            {
                answer.push_back(res[idx].second);
                idx++;
            }
        }

    }
    
    sort(answer.begin(), answer.end());
    return answer;
}