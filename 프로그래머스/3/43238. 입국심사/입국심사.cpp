#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long func(long long m, vector<int>& times)
{
    long long sum = 0;
    for(auto& t: times)
        sum += m/t;
    return sum;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long s = 1;
    long long e = (long long)times.back() * n;
    
    while(s <= e)
    {
        long long m = s + (e-s)/2;
        if(func(m, times) >= n)
        {
            answer = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }
    return answer; 
}