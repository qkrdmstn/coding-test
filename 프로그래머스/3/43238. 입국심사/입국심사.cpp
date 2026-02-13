#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long Result(long long time, vector<int>& times)
{
    long long sum = 0;
    for(int i=0; i<times.size(); i++)
    {
        sum += time/times[i];
    }
    return sum;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long s = 1;
    long long e = n*times[times.size()-1];
    while(s<e)
    {
        long long m = (s+e)/2;
        if(Result(m, times) >= n)
            e = m;
        else
            s = m+1;
        if(s>=e) break;
    }
    return s;
}