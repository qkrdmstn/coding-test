#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(vector<string>& candidate_id, vector<string>& banned_id)
{
    for(int i=0; i<banned_id.size(); i++)
    {
        if(banned_id[i].length() != candidate_id[i].length()) return false;
        
        int len = banned_id[i].length();
        for(int j=0; j<len; j++)
        {
            if(banned_id[i][j] == '*') continue;
            if(banned_id[i][j] != candidate_id[i][j]) return false;
        }
    }
    
    return true;
}

void dfs2(vector<bool>& used, vector<string>& candidate,vector<string>& banned_id, vector<string>& res, bool& ans)
{
    if(ans) return;
    if(res.size() == candidate.size())
    {
        if(check(res, banned_id)) ans = true;
        return;
    }
    
    for(int i=0; i<candidate.size(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        res.push_back(candidate[i]);
        dfs2(used, candidate, banned_id, res, ans);
        res.pop_back();
        used[i] = false;
    }
}

void dfs(int idx, vector<string>& user_id, vector<string>& banned_id, vector<string>& candidate_id, int& ans)
{
    if(candidate_id.size() == banned_id.size())
    {
        vector<bool> used(candidate_id.size(), false);
        vector<string> v;
        bool result = false;
        dfs2(used, candidate_id, banned_id, v, result);
        if(result) ans++;
        return;
    }
    
    for(int i=idx; i<user_id.size(); i++)
    {
        candidate_id.push_back(user_id[i]);
        dfs(i + 1, user_id, banned_id, candidate_id, ans);
        candidate_id.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    

    for(auto& c: banned_id)
        cout << c << " ";
    cout << "----------------------------\n\n";
    
    vector<string> candidate_id;
    dfs(0, user_id, banned_id, candidate_id, answer);
    return answer;
}