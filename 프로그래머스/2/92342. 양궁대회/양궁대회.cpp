#include <string>
#include <vector>

using namespace std;
int CalcScoreDiff(const vector<int>& res, const vector<int>& info)
{
    // A: 어피치, B: 라이언
    int scoreA = 0, scoreB = 0;
    for(int i=0; i<11; i++)
    {
        int score = 10-i;
        if(info[i] == 0 && res[i] == 0) continue;
        if(info[i] >= res[i]) scoreA += score;
        else scoreB += score;
    }
    return scoreB-scoreA;
}

bool IsFirst(const vector<int>& curRes, const vector<int>& result)
{
    for(int i=10; i>=0; i--)
    {
        if(curRes[i] > result[i]) return true;
        if(curRes[i] < result[i]) return false;
    }
    return false;
}

void DFS(int depth, int curArrow, vector<int>& curRes, vector<int>& result, int& maxDiff, const vector<int>& info)
{
    if(depth == 11)
    {
        curRes[10] += curArrow;
        int diff = CalcScoreDiff(curRes, info);
        if(diff > maxDiff)
        {
            maxDiff = diff;
            result = curRes;
        }
        else if(diff == maxDiff)
        {
            if(IsFirst(curRes, result)) result = curRes;
        }
        curRes[10] -= curArrow;
        return;
    }
    
    if(curArrow > info[depth])
    {
        int reqArrow = info[depth] + 1;
        curRes[depth] += reqArrow;
        DFS(depth+1, curArrow - reqArrow, curRes, result, maxDiff, info);
        curRes[depth] -= reqArrow;
    }
    
    DFS(depth+1, curArrow, curRes, result, maxDiff, info);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    vector<int> curRes(11, 0);
    int maxDiff = -0x3f3f3f3f;
    DFS(0, n, curRes, answer, maxDiff, info);
    
    if(maxDiff <= 0) return {-1};
    return answer;
}