#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    stations.push_back(n+w+1);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    int cnt = 0;
    int cur = 1;
    int range = 2 * w + 1;
    for(int i=0; i<stations.size(); i++)
    {
        int ed = stations[i]-w-1;
        int dist = ed - cur + 1;
        if(dist > 0)
        {
            cnt += dist/range;
            if(dist%range != 0) cnt++;
        }
        cur = stations[i] + w + 1;
    }
    return cnt ;
}