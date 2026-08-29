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
    
    // A 내림차, B 오름차순으로 정렬
    // i+1번째의 A는 i번째의 A보다 낮기 때문에 i+1번째의 B가 i번째의 B보다 낮으면 인센티브 대상이 아닙니다.
    // 또한, A가 같을 때 B가 낮으면 인센티브 대상이기 때문에 B를 오름차순으로 정렬합니다.
    sort(scores.begin(), scores.end(), cmp);
    
    vector<int> sum;
    int maxB = scores[0][1]; // 지나온 점수 중 B의 최대값을 저장합니다.
    for(const auto& score: scores)
    {
        if(score[1] < maxB)
        {
            // 완호가 인센티브 대상이 아닌 경우
            if(score[0] == wanhoA && score[1] == wanhoB) 
                return -1;
            continue;
        }
        maxB = score[1];
        sum.push_back(score[0] + score[1]);
    }
    
    // 인센티브 대상자들의 점수 합을 내림차순 정렬합니다.
    sort(sum.begin(), sum.end(), greater<int>());
    for(const auto& s: sum)
    {
        if(s == wanhoA + wanhoB) break;
        answer++;
    }
    return answer + 1;
}