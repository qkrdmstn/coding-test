#include <string>
#include <vector>

using namespace std;

void DFS(int curSheep, int curWolf, vector<int>& candidate, int& maxSheep,
         const vector<int>& info, const vector<vector<int>>& adj)
{
    if(curSheep > maxSheep)
        maxSheep = curSheep;

    // 지금까지 방문했던 노드와 인접한 노드를 candidate로 저장하고, 방문 가능해질 때 방문합니다.
    for(const int& nxt: candidate)
    {
        // 후보 노드에 방문한 경우 늑대가 같거나 많아지지 않는지 확인합니다.
        int nxtSheep = curSheep;
        int nxtWolf = curWolf;
        if(info[nxt] == 0) nxtSheep++;
        else nxtWolf++;

        // 늑대가 양과 같거나 많아지면 방문하지 못합니다.
        if(nxtWolf >= nxtSheep) continue;
        
        // 방문 가능한 경우
        vector<int> newCandidate;
        for(const int& c: candidate)
        {
            // 방금 방문한 노드를 제외합니다.
            if(c == nxt) continue;
            newCandidate.push_back(c);
        }
        // 현재 방문한 노드와 인접한 노드를 후보지에 추가합니다.
        for(const int& e: adj[nxt])
            newCandidate.push_back(e);
        
        DFS(nxtSheep, nxtWolf, newCandidate, maxSheep, info, adj);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    int n = info.size();
    vector<vector<int>> adj(n);
    for(const auto& e: edges)
        adj[e[0]].push_back(e[1]);
    
    vector<int> candidate = {0};
    DFS(0, 0, candidate, answer, info, adj);
    return answer;
}