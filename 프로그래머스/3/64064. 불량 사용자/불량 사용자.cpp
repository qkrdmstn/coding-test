#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool matched(string user, string banned)
{
    if(user.length() != banned.length()) return false;
    
    for(int i=0; i<user.length(); i++)
    {
        if(banned[i] == '*') continue;
        if(user[i] != banned[i]) return false;
    }
    return true;
} 

void DFS(vector<string>& user_id, vector<string>& banned_id, vector<bool>& used, set<int>& candidate, set<set<int>>& result)
{
    if(candidate.size() == banned_id.size())
    {

        result.insert(candidate);

        return;
    }
    
    for(int i=0; i<user_id.size(); i++)
    {
        if(used[i]) continue;
        if(!matched(user_id[i], banned_id[candidate.size()])) continue;
        //cout << user_id[i] << " " << banned_id[candidate.size()] <<"\n";

        used[i] = true;
        candidate.insert(i);
        DFS(user_id, banned_id, used, candidate, result);
        used[i] = false;
        candidate.erase(i);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<bool> used(user_id.size(), false);
    set<int> candidate;
    set<set<int>> result;
    
    DFS(user_id, banned_id, used, candidate, result);
    return result.size();
}