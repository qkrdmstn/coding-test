#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 각 바위 사이의 거리가 설정된 minDist보다 크거나 같도록 배치할 때, 
// 몇 개의 바위를 부숴야 하는지 확인합니다.
int check(long long minDist, vector<int>& rocks)
{
    long long cur = 0;
    int cnt = 0;
    for(int i=0; i<rocks.size(); i++)
    {
        int dist = rocks[i] - cur;
        if(dist < minDist)
            cnt++;
        else
            cur = rocks[i];
    }
    return cnt;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    // 이분탐색으로 바위 사이의 최소 거리를 설정합니다.
    long long st = 1;
    long long ed = distance;
    while(st <= ed)
    {
        long long m = st + (ed-st)/2;
        // 주어진 개수보다 많은 바위를 부술 경우 최소 거리를 좁힙니다.
        if(check(m, rocks) > n)
            ed = m-1;
        // 주어진 개수보다 적은 바위를 부술 경우 최소 거리를 늘릴 수 있습니다.
        else
        {
            answer = m;
            st = m+1;
        }
    }
    return answer;
}