#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> restDays;
    stack<int> s;
    
    for(int i=progresses.size() - 1; i>=0; i--)
    {
        int restDay = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) restDay++;
        s.push(restDay);
    }
    
    int maxDays = s.top();
    while(1)
    {
        int cnt = 0;
        while(!s.empty() && s.top() <= maxDays)
        {
            s.pop();
            cnt++;
        }
        answer.push_back(cnt);
        if(s.empty()) break;
        maxDays = s.top();
    }
    return answer;
}