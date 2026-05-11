#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    answer = 1;
    int lastPos = routes[0][1];
    for(auto& route: routes)
    {
        if(route[0] > lastPos)
        {
            answer++;
            lastPos = route[1];
        }
    }
    return answer;
}