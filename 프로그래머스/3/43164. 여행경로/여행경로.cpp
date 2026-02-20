#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(string curCity, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& answer)
{
    answer.push_back(curCity);
    if(answer.size() == tickets.size() + 1) return true;
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i][0] != curCity || used[i]) continue;
        used[i] = true;
        if(DFS(tickets[i][1], tickets, used, answer)) return true;
        used[i] = false;
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> used(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, used, answer);
    return answer;
}