#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue
        <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        requestPQ; //{요청 시간, 작업 시간}
     priority_queue
        <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
         waitPQ; //{작업 시간, 요청 시간}

    for(int i=0; i<jobs.size(); i++)
        requestPQ.push({jobs[i][0], jobs[i][1]});
    
    int curTime = 0;
    while(!requestPQ.empty() || !waitPQ.empty())
    {
        //대기 큐는 비어있는데, 요청할 작업이 남아 있다면 다음 요청 시간으로 건너 뛰기
        if(waitPQ.empty() && !requestPQ.empty())
        {
            curTime = requestPQ.top().first;
            waitPQ.push({requestPQ.top().second, requestPQ.top().first});
            requestPQ.pop();
        }
        int duration = waitPQ.top().first;
        int request = waitPQ.top().second;
        waitPQ.pop();
        
        curTime += duration; 
        answer += (curTime - request); 
        
        //현재 시간보다 요청 시간이 먼저인 작업들을 대기 큐에 삽입합니다.
        while(!requestPQ.empty() && requestPQ.top().first <= curTime)
        {
            waitPQ.push({requestPQ.top().second, requestPQ.top().first});
            requestPQ.pop();
        }
    }
    return answer / jobs.size();
}