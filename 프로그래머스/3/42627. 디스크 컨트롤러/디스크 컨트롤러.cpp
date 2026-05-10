#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    priority_queue
        <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        jobQueue; //{요청 시각, 소요 시간}
    priority_queue
        <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        waitQueue; //{소요 시간, 요청 시각}

    for(auto& job: jobs)
        jobQueue.push({job[0], job[1]});

    while(!jobQueue.empty() || !waitQueue.empty())
    {
        while(!jobQueue.empty() && jobQueue.top().first <= curTime)
        {
            waitQueue.push({jobQueue.top().second, jobQueue.top().first});
            jobQueue.pop();
        }
        //현재 시각에 대기 중인 작업이 없는 경우, 점프
        if(!jobQueue.empty() && waitQueue.empty())
        {
            curTime = jobQueue.top().first;
            continue;            
        }
        curTime += waitQueue.top().first;
        //반환 시간 = 작업 종료 시각 - 요청 시각
        answer += curTime - waitQueue.top().second;
        waitQueue.pop();
    }
    return answer/jobs.size();
}