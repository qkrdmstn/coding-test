#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    //{작업 시간, 요청 시간}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitPQ;
    //{요청 시간, 작업 시간}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reqPQ;
    
    for(auto &job :jobs)
        reqPQ.push({job[0], job[1]});

    int curTime = 0;
    while(!reqPQ.empty() || !waitPQ.empty())
    {
        while(!reqPQ.empty() && reqPQ.top().first <= curTime)
        {
            waitPQ.push({reqPQ.top().second, reqPQ.top().first});
            reqPQ.pop();
        }
        
        if(waitPQ.empty() && !reqPQ.empty())
        {
            curTime = reqPQ.top().first;
            continue;
        }
        
        auto job = waitPQ.top(); waitPQ.pop();
        curTime += job.first;
        answer += curTime - job.second;
    }
    answer /= jobs.size();
    return answer;
}