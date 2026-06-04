#include <string>
#include <vector>
using namespace std;

bool CanCross(int people, vector<int>& stones, int k)
{
    int cnt = 0;
    for(const auto& stone: stones)
    {
        // n명이 지날 수 없는 디딤돌이 k개 연속 있는 경우
        // 여러 돌을 건너뛰어도 오른편으로 도달할 수 없습니다.
        if(stone - people < 0)
        {
            cnt++;
            // 지날 수 없는 디딤돌이 연속으로 k개 이상인 경우
            if(cnt >= k) return false;
        }
        // 중간에 지날 수 있는 디딤돌이 존재한다면 건너뛰어 도달 가능합니다.
        else
            cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 이분탐색으로 건널 수 있는 인원수를 탐색합니다.
    int st = 0;
    int ed = 200'000'000;
    while(st <= ed)
    {
        // 이번 루프에서 확인할 인원수를 지정합니다.
        int n = st + (ed - st) / 2;
        
        // n명이 건널 수 있다면 n은 유효합니다.
        if(CanCross(n, stones, k))
        {
            answer = n;
            // 더 많은 인원수가 건널 수 있는지 확인하기 위해
            // 범위를 오른쪽 절반으로 확장합니다.
            st = n + 1;
        }
        // 건널 수 없다면 인원수를 왼쪽 절반으로 줄입니다.
        else
            ed = n - 1;
    }
    return answer;

}