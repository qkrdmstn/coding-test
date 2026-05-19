#include <string>
#include <vector>

using namespace std;

// DFS로 현재 상태로부터 다음 방문 가능한 노드들을 업데이트하며 그곳을 순회합니다.
void DFS(int sheep, int wolf, vector<int>& info, vector<vector<int>>& child, vector<int>& candidate, int& ans)
{
    ans = max(ans, sheep);
    
    // 현재 방문 가능한 후보들 순회
    for(auto& cand: candidate)
    {
        // 다음 노드 방문 시, 양과 늑대 세기
        int newSheep = (info[cand] == 0) ? sheep + 1 : sheep;
        int newWolf = (info[cand] == 1) ? wolf + 1 : wolf;
        if(newWolf >= newSheep) continue; // 늑다 >= 양이면 다음 노드 방문 못함
        
        // 다음 후보지들 정리
        vector<int> nxtCand;
        for(auto& curCand: candidate)
        {
            // 지금 정해진 곳 제외한 나머지 후보지들 그대로 넘기기
            if(curCand != cand) nxtCand.push_back(curCand);
        }
        // 현재 노드의 자식 노드들도 후보지에 넣기
        for(auto& ch: child[cand])
            nxtCand.push_back(ch);
        DFS(newSheep, newWolf, info, child, nxtCand, ans);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> child(info.size());
    for(auto& e: edges)
        child[e[0]].push_back(e[1]);
    
    DFS(1, 0, info, child, child[0], answer);
    
    return answer;
}