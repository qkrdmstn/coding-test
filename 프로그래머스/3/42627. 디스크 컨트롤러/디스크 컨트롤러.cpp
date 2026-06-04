#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 최소 힙을 통해 정해진 우선순위에 따라 작업을 선택할 수 있도록 합니다.
    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> reqPQ; // {요청 시각, 소요 시간, 작업 번호}
    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> waitPQ; // {소요 시간, 요청 시각, 작업 번호}
    
    // 요청 힙에 작업들을 모두 넣어 요청시각 우선으로 오름차순 정렬합니다.
    int n = jobs.size();
    for(int i=0; i<n; i++)
    {
        int s = jobs[i][0], l = jobs[i][1];
        reqPQ.push({s, l, i});
    }
    
    int curTime = 0;
    // 모든 요청이 완료될 때까지 작업을 수행합니다.
    while(!reqPQ.empty() || !waitPQ.empty())
    {
        // 요청 시각이 현재 시간보다 이전이라면 대기 큐에 작업을 삽입합니다.
        while(!reqPQ.empty())
        {
            int s, l, i;
            tie(s, l, i) = reqPQ.top();
            if(curTime < s) break;
            reqPQ.pop();
            waitPQ.push({l, s, i});
        }
        
        // 현재 시간보다 이전에 온 요청이 없으면 가장 빠른 다음 요청으로 시간을 건너뜁니다.
        if(waitPQ.empty() && !reqPQ.empty())
        {
            int s, l, i;
            tie(s, l, i) = reqPQ.top();
            curTime = s;
            continue;
        }
        
        // 대기 큐에 있는 우선순위가 가장 높은 작업을 수행합니다.
        int l, s, i;
        tie(l, s, i) = waitPQ.top(); waitPQ.pop();
        
        // 작업 소요 시간만큼 현재 시간을 이동시키고, 반환 시간을 계산합니다.
        curTime += l;
        answer += (curTime - s);
    }
    
    // 평균을 계산합니다.
    return answer/n;
}