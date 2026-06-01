#include <string>
#include <vector>

using namespace std;
const int INF = 1'000'000'001;
int solution(vector<int> a) {
    int answer = 0;
    
    // 각각 좌/우로부터 시작해 i번째까지 가장 작은 수를 기록합니다.
    int n = a.size();
    vector<int> minLeft(n, INF);
    vector<int> minRight(n, INF);
    
    minLeft[0] = a[0];
    minRight[n-1] = a[n-1];
    for(int i=1; i<n; i++)
    {
        minLeft[i] = min(minLeft[i-1], a[i]);
        minRight[n-1-i] = min(minRight[n-i], a[n-1-i]);
    }
    
    // 현재 풍선은 양쪽의 가장 최소값을 가진 풍선보다 하나라도 작으면 최후까지 남을 수 있습니다.
    for(int i=1; i<n-1; i++)
    {
        if(a[i] < minLeft[i-1] || a[i] < minRight[i+1])
            answer++;
    }

    // 양쪽 끝 풍선은 반드시 최후까지 남을 수 있습니다.
    return answer + 2;
}