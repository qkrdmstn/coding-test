#include <string>
#include <vector>
#include <set>
using namespace std;

bool IsMatch(string& user, string banned)
{
    if(user.length() != banned.length()) return false;
    
    int len = banned.length();
    for(int i=0; i<len; i++)
    {
        if(banned[i] == '*') continue;
        if(banned[i] != user[i]) return false;
    }
    return true;
}

// 각 depth당 banned_id에 매치되는 user_Id를 하나씩 선택해 나아간다.
void DFS(int depth, vector<bool>& used, vector<string>& user_id, vector<string>& banned_id, set<int>& res, set<set<int>>& ans)
{
    // 중복 제거를 위해 set 자료구조에 삽입
    if(depth == banned_id.size())
    {
        ans.insert(res);
        return;
    }
    
    for(int i=0; i<user_id.size(); i++)
    {
        // 이전 depth 에서 이미 사용된 user_id라면 건너뛴다,
        if(used[i]) continue;
        if(!IsMatch(user_id[i], banned_id[depth])) continue;
        used[i] = true;
        res.insert(i);
        DFS(depth + 1, used, user_id, banned_id, res, ans);
        res.erase(i);
        used[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    set<set<int>> ans;
    vector<bool> used(user_id.size(), false);
    set<int> res;
    DFS(0, used, user_id, banned_id, res, ans);
    return ans.size();
}