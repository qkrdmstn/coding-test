#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool func(string cur, int n, vector<bool>& used, vector<vector<string>>& tickets, vector<string>& arr, vector<vector<string>>& answers)
{
    if(arr.size() == n + 1)
    {
        answers.push_back(arr);
        return true;
    }
    for(int i=0; i<n; i++)
    {
        if(used[i] || tickets[i][0] != cur) continue;
        used[i] = true;
        arr.push_back(tickets[i][1]);
        if(func(tickets[i][1], n, used, tickets, arr, answers)) return true;
        arr.pop_back();
        used[i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    
    vector<bool> used(n);
    vector<vector<string>> answers;
    sort(tickets.begin(), tickets.end());
    
    answer.push_back("ICN");
    func("ICN", n, used, tickets, answer, answers);
    return answer;
}