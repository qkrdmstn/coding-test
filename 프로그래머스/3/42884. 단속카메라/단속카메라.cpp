#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& r1, const vector<int>& r2)
{
    return r1[1] < r2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int num = routes.size();
    
    // 진출 지점 기준 오름차순으로 정렬합니다.
    sort(routes.begin(), routes.end(), cmp);
    
    // 설치된 마지막 카메라의 위치를 저장합니다.
    int lastCameraPos = routes[0][1];
    answer = 1;
    
    for(const auto r: routes)
    {
        // 진출지점 기준으로 정렬돼있기 때문에, 진입 지점이 카메라보다 앞선다면 
        // 카메라를 만납니다.
        if(r[0] <= lastCameraPos) continue;
        
        // 만나지 못하면, 진출 지점에 카메라를 설치합니다.
        lastCameraPos = r[1];
        answer++;
    }
    return answer;
}