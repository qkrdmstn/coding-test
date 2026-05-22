#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// result가 제재 아이디가 될 수 있는지 확인합니다.
bool IsPossible(vector<string>& result, vector<string>& banned_id)
{
    int n = result.size();
    for(int i=0; i<n; i++)
    {
        if(result[i].length() != banned_id[i].length()) return false;
        int len = result[i].length();
        for(int j=0; j<len; j++)
        {
            if(banned_id[i][j] == '*') continue;
            if(result[i][j] != banned_id[i][j]) return false;
        }
    }
    return true;
}

// DFS를 활용해 user_id 중 banned_id와 같은 개수를 뽑아 나열하는 경우를 확인합니다.
void DFS(vector<bool>& used, vector<string>& user_id, vector<string>& banned_id, vector<string>& result, set<set<string>>& answers)
{
    // 불량 사용자 개수와 같은 개수를 뽑습니다.
    if(result.size() == banned_id.size())
    {
        if(IsPossible(result, banned_id))
        {
            // 정해진 순열 중 중복을 방지하기 위해 set을 통해 저장합니다.
            set<string> r(result.begin(), result.end());
            answers.insert(r);
        }
        return;
    }
    
    for(int i=0; i<user_id.size(); i++)
    {
        if(used[i]) continue;
        result.push_back(user_id[i]);
        used[i] = true;
        DFS(used, user_id, banned_id, result, answers);
        used[i] = false;
        result.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<bool> used(user_id.size(), false);
    vector<string> result;
    set<set<string>> answers;
    DFS(used, user_id, banned_id, result, answers);
    return answers.size();
}