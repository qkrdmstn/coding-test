#include <string>
#include <vector>

using namespace std;

typedef long long ll;

// totalTime 동안 모든 심사관이 몇 명을 심사할 수 있는지 계산하는 함수입니다.
ll HowManyPeopleJudge(ll totalTime, vector<int>& times)
{
    ll cnt = 0;
    for(const auto& t: times)
        cnt += totalTime/t;
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    ll st = 1;
    // n*times[0] 연산 시 발생할 수 있는 오버플로우를 방지하기 위해
    // long long 타입으로 명시적 형변환을 수행합니다.
    ll ed = (ll)n * times[0];
    
    // 이분탐색으로 정해진 시간 내에 몇 명의 사람을 심사할 수 있는지 탐색합니다.
    while(st<=ed)
    {
        ll t = st + (ed - st) / 2;
        
        // 시간 t가 기다리는 사람을 모두 심사할 수 있는 시간인 경우
        // t는 유효한 해입니다.
        if(HowManyPeopleJudge(t, times) >= n)
        {
            // 유효해를 기록합니다.
            answer = t;
            // 최적해(최소 시간)을 계산하기 위해 좌측 범위로 구간을 변경합니다.
            ed = t - 1;
        }
        // t가 유효하지 않은 경우 우측 구간(시간 증가)에서 유효해 탐색을 이어나갑니다. 
        else 
            st = t + 1;
    }
    return answer;
}