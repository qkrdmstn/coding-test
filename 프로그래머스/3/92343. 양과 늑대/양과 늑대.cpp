#include <string>
#include <vector>
using namespace std;

void DFS(int curSheep, int curWolf, vector<int>& info, vector<vector<int>>& child, vector<int>& candidates, int& ans)
{
    ans = max(curSheep, ans);
    for(auto& nxt: candidates)
    {
        // nxt 노드를 방문했을 때, 양과 늑대를 계산합니다.
        int newSheep = (info[nxt] == 0) ? curSheep + 1 : curSheep;
        int newWolf = (info[nxt] == 0) ? curWolf : curWolf + 1;
        
        // 늑대의 수가 양의 수보다 같거나 클 경우 방문이 불가능합니다.
        if(newSheep <= newWolf) continue;
        
        // 다음 방문 가능한 후보지들을 갱신합니다. 이때 현재 방문지를 제외합니다.
        vector<int> nxtCandidates;
        for(int i=0; i<candidates.size(); i++)
        {
            if(candidates[i] == nxt) continue;
            nxtCandidates.push_back(candidates[i]);
        }
        
        // 현재 방문지와 연결된 노드들도 포함합니다.
        for(const auto& c: child[nxt])
            nxtCandidates.push_back(c);
        DFS(newSheep, newWolf, info, child, nxtCandidates, ans);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    int n = info.size();
    vector<vector<int>> child(n);
    for(const auto& e: edges)
        child[e[0]].push_back(e[1]);

    DFS(1, 0, info, child, child[0], answer);
    return answer;
}