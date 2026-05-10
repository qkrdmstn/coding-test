#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool IsBetter(vector<int>& cur, vector<int>& best)
{
    for(int i=10; i>=0; i--)
    {
        if(cur[i] > best[i]) return true;
        if(cur[i] < best[i]) return false;
    }
    return false;
}
int CalcDiff(vector<int>& target, vector<int>& info)
{
    int score1 = 0; //라이언 점수
    int score2 = 0; //어피치 점수
    for(int i=0; i<11; i++)
    {
        if(target[i] == 0 && info[i] == 0)
            continue;
        else if(target[i] > info[i])
            score1 += 10 - i;
        else score2 += 10 - i;
    }
    return score1 - score2;
}

void DFS(int curTarget, int arrows, vector<int>& target, vector<int>& info, int& maxDiff, vector<int>& answer)
{
    if(curTarget == 11)
    {
        if(arrows >= 0)
            target[10] += arrows;
        int curDiff = CalcDiff(target, info);
        if(curDiff > maxDiff)
        {
            answer = target;
            maxDiff = curDiff;
        }
        else if(curDiff == maxDiff)
        {
            if(IsBetter(target, answer))
                answer = target;
        }
        target[10] -= arrows;
        return;
    }
    
    //현재 타겟(k점 과녁)을 가져오는 경우
    if(arrows > info[curTarget])
    {
        target[curTarget] = info[curTarget] + 1;
        DFS(curTarget + 1, arrows - target[curTarget], target, info, maxDiff, answer);
        target[curTarget] = 0;
    }
    //안가져오는 경우
    DFS(curTarget + 1, arrows, target, info, maxDiff, answer);
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    int maxDiff = -0x3f3f3f3f;
    vector<int> target(11, 0);
    DFS(0, n, target, info, maxDiff, answer);
    if(maxDiff <= 0) answer = {-1};
    return answer;
}