#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for(int i=0; i<progresses.size(); i++)
    {
        int restDay = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i] != 0) restDay++;
        q.push(restDay);
    }
    
    while(!q.empty())
    {
        int curDay = q.front();
        int count = 0;
        while(!q.empty() && curDay >= q.front())
        {
            q.pop();
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}