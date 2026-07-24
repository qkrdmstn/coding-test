#include <string>
#include <vector>
#include <set>
using namespace std;

bool Matched(string& user, string& banned)
{
    if(user.length() != banned.length()) return false;
    for(int i=0; i<user.length(); i++)
    {
        if(banned[i] == '*') continue;
        if(user[i] != banned[i]) return false;
    }
    return true;
}

void DFS(int depth, vector<bool>& used, vector<string>& user_id, vector<string>& banned_id, set<int>& candidate, set<set<int>>& result)
{
    if(depth == banned_id.size())
    {
        result.insert(candidate);
        return;
    }

    for(int i=0; i<user_id.size(); i++)
    {
        if(used[i]) continue;
        if(!Matched(user_id[i], banned_id[depth])) continue;
        
        used[i] = true;
        candidate.insert(i);
        DFS(depth + 1, used, user_id, banned_id, candidate, result);
        used[i] = false;
        candidate.erase(i);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    vector<bool> used(user_id.size(), false);
    set<int> candidate;
    set<set<int>> result;
    
    DFS(0, used, user_id, banned_id, candidate, result);
    return result.size();
}