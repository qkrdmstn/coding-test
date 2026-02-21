#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];    
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    //진출 지점 기준 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);
    int lastCameraPos = -30001;
    for(const auto& route: routes)
    {
        //현재 차량의 진입 위치가 마지막 카메라 위치보다 뒤라면
        if(lastCameraPos < route[0])
        {
            //현재 차량을 위한 카메라를 차량 진출 지점에 설치
            answer++;
            lastCameraPos = route[1];
        }
    }
    return answer;
}