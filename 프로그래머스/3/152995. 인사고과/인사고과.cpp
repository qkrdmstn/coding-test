#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    // A: 근무 태도 점수, B: 동료 평가 점수
    int wanhoA = scores[0][0];
    int wanhoB = scores[0][1];
    sort(scores.begin(), scores.end(), cmp);
    
    vector<int> sum;
    int maxB = scores[0][1];
    for(const auto& score: scores)
    {
        if(score[1] < maxB)
        {
            if(score[0] == wanhoA && score[1] == wanhoB)
                return -1;
            continue;
        }
        sum.push_back(score[0] + score[1]);
        maxB = score[1];
    }
    sort(sum.begin(), sum.end(), greater<int>());
    
    for(const int& s: sum)
    {
        if(s == wanhoA + wanhoB) break;
        answer++;
    }
    return answer+1;
}