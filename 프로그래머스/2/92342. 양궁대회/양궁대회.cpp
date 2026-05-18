#include <string>
#include <iostream>
#include <vector>

using namespace std;

int ClacScore(vector<int>& res, vector<int>& info)
{
    // 라이언, 어피치 점수
    int score1 = 0, score2 = 0;
    for(int i=0; i<11; i++)
    {
        if(res[i] == info[i]) continue;
        else if(res[i] > info[i]) score1 += 10 - i;
        else score2 += 10 - i;
    }
    return score1 - score2;
}

bool IsFirst(vector<int>& res, vector<int>& ans)
{
    for(int i=10; i>=0; i--)
    {
        cout << "i: " << i << " " << res[i] << " " << ans[i] << "\n";
        if(res[i] > ans[i]) {cout << "true\n"; return true;}
        if(res[i] < ans[i]) {cout << "false\n"; return false;}
    }
    return false;
}

void DFS(int idx, int restArrow, vector<int>& info, vector<int>& res, int& maxScore, vector<int>& ans)
{
    if(res.size() == info.size())
    {
        res[10] += restArrow;
        int curScore = ClacScore(res, info);
        if(curScore > maxScore)
        {
            maxScore = curScore;
            ans = res;
        }
        else if(curScore == maxScore)
        {
            if(IsFirst(res, ans)) ans = res;
        }
    
        res[10] -= restArrow;
        return;
    }
    
    // 현재 점수를 가져오는 경우
    if(restArrow > info[idx])
    {
        int useArrow = info[idx] + 1;
        res.push_back(useArrow);
        DFS(idx + 1, restArrow - useArrow, info, res, maxScore, ans);
        res.pop_back();
    }
    
    // 현재 점수를 포기하는 경우
    res.push_back(0);
    DFS(idx+1, restArrow, info, res, maxScore, ans);
    res.pop_back();
}


vector<int> solution(int n, vector<int> info) {
    int maxScore = -0x3f3f3f3f;
    vector<int> res;
    vector<int> answer(11, 0);
    DFS(0, n, info, res, maxScore, answer);
    
    if(maxScore <= 0) answer = {-1};
    return answer;
}