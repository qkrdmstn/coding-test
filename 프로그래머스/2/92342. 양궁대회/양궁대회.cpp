#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isBetter(vector<int>& cur, vector<int>& best) {
    for (int i = 10; i >= 0; i--) {
        if (cur[i] > best[i]) return true;
        if (cur[i] < best[i]) return false;
    }
    return false;
}

int ClacScore(vector<int>& res, vector<int>& info)
{
    //라이언, 어피치 점수
    int score1 = 0, score2 = 0;
    for(int i=0; i<=10; i++)
    {
        if(res[i] == 0 && info[i] == 0)
            continue;
        else if(res[i] > info[i])
            score1 += 10-i;
        else score2 += 10 - i;
    }
    return score1 - score2;
}

void DFS(int idx, int arrows, vector<int>& curRes, vector<int>& info, int& maxScoreDiff, vector<int>& res)
{
    if(idx == 11)
    {
        curRes[10] += arrows;
        int curScoreDiff = ClacScore(curRes, info);
        if(curScoreDiff > maxScoreDiff)
        {
            maxScoreDiff = curScoreDiff;
            res = curRes;
        }
        else if(curScoreDiff > 0 && curScoreDiff == maxScoreDiff)
        {
            if(isBetter(curRes, res)) res = curRes;
        }
        curRes[10] -= arrows;
        return;
    }
    
    //현재 과녁을 포기함
    DFS(idx + 1, arrows, curRes, info, maxScoreDiff, res);
    
    int needs = info[idx] + 1;
    if(arrows >= needs)
    {
        curRes[idx] = needs;
        DFS(idx + 1, arrows - needs, curRes, info, maxScoreDiff, res);
        curRes[idx] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    vector<int> res;
    vector<int> curRes(11, 0);
    int maxScoreDiff = -0x3f3f3f3f;
    DFS(0, n, curRes, info, maxScoreDiff, res);
    if(maxScoreDiff <= 0) answer.push_back(-1);
    else return res;
    return answer;
}