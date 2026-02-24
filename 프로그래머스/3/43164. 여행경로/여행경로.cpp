#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Backtracking(vector<string> &curPath, vector<bool>& used, vector<vector<string>>& tickets)
{
    if(curPath.size() == tickets.size() + 1)
    {
        return true;
    }
    for(int i=0; i<tickets.size(); i++)
    {
        if(used[i] || tickets[i][0] != curPath.back()) continue;
        used[i] = true;
        curPath.push_back(tickets[i][1]);
        if(Backtracking(curPath, used, tickets)) return true;
        curPath.pop_back();
        used[i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> used(tickets.size(), false);
    answer.push_back("ICN");
    
    sort(tickets.begin(), tickets.end());
    Backtracking(answer, used, tickets);
    return answer;
}