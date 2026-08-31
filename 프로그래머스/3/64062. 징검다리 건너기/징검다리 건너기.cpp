#include <string>
#include <vector>

using namespace std;

bool CanCross(int people, const vector<int> stones, int k)
{
    int cnt = 0;
    for(const auto& stone: stones)
    {
        if(stone < people)
        {
            cnt++;
            if(cnt >= k) return false;
        }
        else
            cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int st = 1;
    int ed = 200'000'000;
    while(st <= ed)
    {
        int mid = st + (ed - st) / 2;
        if(CanCross(mid, stones, k))
        {
            answer = mid;
            st = mid + 1;
        }
        else 
            ed = mid - 1;
    }
    return answer;
}