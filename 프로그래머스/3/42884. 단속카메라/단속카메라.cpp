#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int idx = 0;
    while(idx < routes.size())
    {
        answer++;
        int pos = routes[idx][1];
        while(idx < routes.size() && routes[idx][0] <= pos)
            idx++;
    }
    return answer;
}