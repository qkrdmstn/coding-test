#include <string>
#include <vector>

using namespace std;

int ChangeBinary(int cur)
{
    int cnt = 0;
    while(cur != 0)
    {
        if(cur % 2 == 1) cnt++;
        cur /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int target = ChangeBinary(n);
    n++;
    while(target != ChangeBinary(n))
    {
        n++;
    }
    return n;
}