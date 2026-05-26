#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int st = 0;
    int curSum = 0;
    for(int ed=1; ed<=n; ed++)
    {
        curSum += ed;
        while(curSum > n)
        {
            curSum -= st;
            st++;
        }
        if(curSum == n) answer++;
    }
    return answer;
}