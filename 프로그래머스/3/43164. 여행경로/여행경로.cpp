#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string cur, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& answer, int targetSize)
{
    answer.push_back(cur);
    if(answer.size() == targetSize) return true;
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i][0] != cur || used[i]) continue;
        used[i] = true;
        if(dfs(tickets[i][1], tickets, used, answer, targetSize)) return true;
        used[i] = false;
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> used(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, used, answer, tickets.size()+1);
    return answer;
}