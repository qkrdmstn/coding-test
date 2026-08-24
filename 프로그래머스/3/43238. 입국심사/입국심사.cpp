#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

ll ClacNumOfPeople(ll totalTime, const vector<int>& times)
{
    ll cnt = 0;
    for(const auto& t: times)
        cnt += totalTime/t;
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    ll st = 1;
    ll ed = (ll)n * times[0];
    while(st <= ed)
    {
        ll mid = st + (ed-st) / 2;
        if(ClacNumOfPeople(mid, times) >= n)
        {
            answer = mid;
            ed = mid-1;
        }
        else
            st = mid+1;   
    }
    return answer;
}