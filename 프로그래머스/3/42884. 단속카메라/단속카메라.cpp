#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];    
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    // 진출 지점 오름차순으로 정렬
    sort(routes.begin(), routes.end(), cmp);
    

    // 첫 번째 차가 나가는 지점에 단속카메라를 하나 설치합니다.
    answer++;
    
    int n = routes.size();
    int lastCameraPos = routes[0][1];
    for(int i=1; i<n; i++)
    {
        // 진출지점 오름차순이기 때문에,
        // 마지막으로 카메라가 설치된 위치보다 앞에서 들어왔으면 해당 카메라와 만납니다.
        if(routes[i][0] <= lastCameraPos) continue;
        
        // 마지막 카메라보다 뒤에 진입한 경우, 해당 차의 진출지점에 카메라를 설치합니다.
        answer++;
        lastCameraPos = routes[i][1];
    }
    
    return answer;
}