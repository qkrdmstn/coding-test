#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    for(auto &v: arr)
        q.push(v);
    
    int lastNum = q.front();
    answer.push_back(lastNum);
    q.pop();
    while(!q.empty())
    {
        if(q.front() != lastNum)
        {
            lastNum = q.front();
            answer.push_back(q.front());
        }
        q.pop();
    }

    return answer;
}