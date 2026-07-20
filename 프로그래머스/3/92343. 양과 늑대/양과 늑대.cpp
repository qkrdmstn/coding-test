#include <string>
#include <vector>

using namespace std;

void DFS(int sheep, int wolf, vector<int> candidate, const vector<int>& info, const vector<vector<int>>& edge, int& answer)
{
    answer = max(answer, sheep);
    
    for(const auto& c1: candidate)
    {
        int newSheep = sheep;
        int newWolf = wolf;
        if(info[c1] == 0) newSheep++;
        else newWolf++;
        if(newSheep <= newWolf) continue;
        
        vector<int> newCandidate;
        for(const auto& c2: candidate)
        {
            if(c1 == c2) continue;
            newCandidate.push_back(c2);
        }
        for(const auto& child: edge[c1])
            newCandidate.push_back(child);
        
        DFS(newSheep, newWolf, newCandidate, info, edge, answer);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<vector<int>> edge(info.size(), vector<int>());
    for(const auto &e: edges)
        edge[e[0]].push_back(e[1]);
    
    DFS(0, 0, {0}, info, edge, answer);
    return answer;
}