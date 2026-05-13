#include <string>
#include <vector>

using namespace std;
void dfs(int sheep, int wolf, vector<int>& info, vector<vector<int>>& child, vector<int> candidates, int& ans)
{
    ans = max(ans, sheep);
    
    for(auto& c: candidates)
    {
        int newSheep = sheep + (info[c] == 0 ? 1 : 0);
        int newWolf = wolf + (info[c] == 1 ? 1 : 0);
        
        if(newWolf >= newSheep) continue;
        
        vector<int> nxt;
        for(auto& c1: candidates)
        {
            if(c1 != c) nxt.push_back(c1);
        }
        for(auto& ch: child[c])
            nxt.push_back(ch);
        dfs(newSheep, newWolf, info, child, nxt, ans);
        
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<vector<int>> child(info.size());
    for(auto& e: edges)
        child[e[0]].push_back(e[1]);
    
    dfs(1, 0, info, child, child[0], answer);
    return answer;
}