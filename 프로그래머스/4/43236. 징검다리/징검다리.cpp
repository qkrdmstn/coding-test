#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int RemoveRockCnt(int minDist, vector<int>& rocks)
{
    int removeCnt = 0;
    int prev = 0;
    for(int i=0; i<(int)rocks.size(); i++)
    {
        int cur = rocks[i];
        int curDist = cur - prev;
        if(curDist < minDist)
        {
            removeCnt++;
            continue;
        }
        prev = cur;
    }
    
    return removeCnt;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    // 도착지점까지의 거리를 계산하기 위해 도착지점을 추가합니다.
    rocks.push_back(distance);
    
    // 이분탐색을 위해 거리순으로 정렬합니다.
    sort(rocks.begin(), rocks.end());
    
    
    int st = 1;
    int ed = distance;
    while(st <= ed)
    {
        int mid = st + (ed - st) / 2;
        if(RemoveRockCnt(mid, rocks) <= n)
        {
            st = mid + 1;
            answer = mid;
        }
        else
            ed = mid - 1;
    }
    return answer;
}