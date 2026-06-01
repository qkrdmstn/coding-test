#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    // A: 근무 태도 점수, B: 동료 평가 점수
    int wanhoA = scores[0][0];
    int wanhoB = scores[0][1];
    
    // A 내림차순, B 오름차순으로 정렬합니다.
    sort(scores.begin(), scores.end(), cmp);
    
    // 정렬에 의해 자신보다 앞에 있는 점수는 A가 무조건 높습니다.
    // 따라서, 앞에 있는 점수들 중 B의 값이 나보다 높다면 둘 다 낮은 것이 됩니다.
    // 앞에서부터 B의 최대값을 추적하여, 다른 사원보다 두 점수가 모두 낮은지 판단합니다.
    vector<int> sums;
    int maxB = scores[0][1];
    for(const auto& score : scores)
    {
        // 현재 사원의 점수는 다른 사원보다 A, B 모두 낮음
        if(score[1] < maxB)
        {
            // 완호의 점수와 같다면 -1 반환
            if(score[0] == wanhoA && score[1] == wanhoB)
                return -1;
            continue;
        }
        // 통과한 점수들은 합을 계산하여 저장합니다.
        sums.push_back(score[0] + score[1]);
        maxB = max(score[1], maxB);
    }
    
    sort(sums.begin(), sums.end(), greater<int>());
    for(int i=0; i<sums.size(); i++)
    {
        if(wanhoA + wanhoB == sums[i]) return i + 1;
    }
    
    return 0;
}