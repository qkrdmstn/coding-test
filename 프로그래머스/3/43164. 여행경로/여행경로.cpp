#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(string cur, vector<bool>& used, vector<vector<string>>& tickets, vector<string>& res, vector<vector<string>>& answer)
{
    if(res.size() == tickets.size() + 1)
    {
        answer.push_back(res);
        return;
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(used[i] || tickets[i][0] != cur) continue;
        res.push_back(tickets[i][1]);
        used[i] = true;
        DFS(tickets[i][1], used, tickets, res, answer);
        used[i] = false;
        res.pop_back();
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<vector<string>> answer;
    
    sort(tickets.begin(), tickets.end());
    vector<bool> used(tickets.size(), false);
    vector<string> res;
    res.push_back("ICN");
    DFS(res[0], used, tickets, res, answer);
    
    return answer[0];
}