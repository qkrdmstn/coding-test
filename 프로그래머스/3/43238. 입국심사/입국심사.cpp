#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long func(long long time, vector<int> times)
{
    long long cnt = 0;
    for(int i=0; i<times.size(); i++)
        cnt += time/times[i];
    return cnt;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long s = 1;
    long long e = (long long)n * times.back();
    while(s <= e)
    {
        long long m = s + (e - s) / 2;
        if(func(m, times) >= n)
        {
            answer = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    return answer;
}