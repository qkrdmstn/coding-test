#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> lost2;
    vector<int> reserve2;
    for(auto l: lost)
    {
        bool found = false;
        for(auto r: reserve)
        {
            if(l == r) found = true;
        }
        if(!found) lost2.push_back(l);
    }
    
    for(auto r: reserve)
    {
        bool found = false;
        for(auto l: lost)
        {
            if(l == r) found = true;
        }
        if(!found) reserve2.push_back(r);
    }
    
    for(int i=0; i<lost2.size(); i++)
    {
        for(int j=answer; j<reserve2.size(); j++)
        {
            if(abs(lost2[i] - reserve2[j]) <= 1)
            {
                answer++;
                break;
            }
        }
    }
    answer += (n-lost2.size());
    return answer;
}