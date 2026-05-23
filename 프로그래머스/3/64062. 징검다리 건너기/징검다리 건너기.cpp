#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool CanCross(int mid, vector<int>& stones, int k)
{
    int cnt = 0;
    for(auto& stone: stones)
    {
        if(stone - mid < 0)
        {
            cnt++;
            if(cnt >= k) return false;
        }
        else cnt = 0;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int st = 1;
    int ed = 200'000'000;
    
    while(st<=ed)
    {
        int mid = st + (ed - st) / 2;
        if(CanCross(mid, stones, k))
        {
            st = mid + 1;
            answer = mid;
        }
        else
            ed = mid - 1;
    }
    return answer;
}