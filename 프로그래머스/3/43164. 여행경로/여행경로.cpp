#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

void dfs(string cur, vector<vector<string>>& tickets, vector<bool>& usedTicket, vector<string>& res, vector<string>& ans)
{
    if(!ans.empty()) return;
    if(res.size() == usedTicket.size() + 1)
    {
        for(auto& r: res)
            cout << r << " ";
        cout << "\n";
        if(ans.empty()) ans = res;
        return;
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(usedTicket[i] || tickets[i][0] != cur) continue;
        usedTicket[i] = true;
        res.push_back(tickets[i][1]);
        dfs(tickets[i][1], tickets, usedTicket, res, ans);
        res.pop_back();
        usedTicket[i] = false;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    int n = tickets.size();
    sort(tickets.begin(), tickets.end());
    
    vector<string> res = {"ICN"};
    vector<bool> usedTicket(n, false);
    dfs("ICN", tickets, usedTicket, res, answer);
    
    return answer;
}