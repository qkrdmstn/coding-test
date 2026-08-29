#include <string>
#include <vector>
#include <set>
using namespace std;

bool IsMatched(const string& user, const string& banned)
{
    if(user.length() != banned.length()) return false;
    for(int i=0; i<(int)user.length(); i++)
    {
        if(banned[i] == '*') continue;
        if(user[i] != banned[i]) return false;
    }
     return true;
}

// DFS 알고리즘을 활용해 현재 banned_id와 매치되는 user_id를 탐색합니다.
void FindCandidate(int depth, vector<bool>& used, set<int>& candidate, set<set<int>>& results, 
                   const vector<string>& user_id, const vector<string>& banned_id)
{
    // 모든 banned_id와 매치되는 user_id를 찾은 경우 결과로 저장합니다.
    if(depth == banned_id.size())
    {
        results.insert(candidate);
        return;
    }
    
    for(int i=0; i<(int)user_id.size(); i++)
    {
        // 이미 매칭됐거나, 매치되지 않는 user_id는 건너뜁니다.
        if(used[i] || !IsMatched(user_id[i], banned_id[depth])) continue;
        
        used[i] = true;
        candidate.insert(i);
        FindCandidate(depth + 1, used, candidate, results, user_id, banned_id);
        candidate.erase(i);
        used[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    // 제재 아이디 후보와 결과를 담을 자료구조를 선언합니다. 이때, 아이디의 순서만 다른 중복을 방지하기 위해 각각 set에 저장합니다.    
    set<int> candidate;
    set<set<int>> results;
    vector<bool> used(user_id.size(), false);
    
    FindCandidate(0, used, candidate, results, user_id, banned_id);
    return results.size();
}