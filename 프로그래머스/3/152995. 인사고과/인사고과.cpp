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
    
    // A를 내림차순, B를 오름차순 정렬
    sort(scores.begin(), scores.end(), cmp);
    
    // 인센티브를 받을 수 있는 인원을 필터링합니다.
    vector<int> sums;
    int maxB = scores[0][1];
    for(const auto& score: scores)
    {
        // A는 이미 내림차순이므로, B가 앞의 최대보다 작으면 인센티브를 받지 못합니다.
        if(score[1] < maxB)
        {
            // 완호가 받지 못하면 즉시 종료합니다.
            if(score[0] == wanhoA && score[1] == wanhoB)
                return -1;
            continue;
        }
        sums.push_back(score[0] + score[1]);
        maxB = max(score[1], maxB);
    }
    
    // 점수의 합을 내림차순으로 정렬합니다.
    sort(sums.begin(), sums.end(), greater<int>());
    for(int i=0; i<(int)sums.size(); i++)
    {
        if(wanhoA + wanhoB == sums[i]) return i+1;
    }
}