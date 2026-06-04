#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> reqPQ; // {요청 시각, 소요 시간, 작업 번호}
    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> waitPQ; // {소요 시간, 요청 시각, 작업 번호}
    
    int n = jobs.size();
    for(int i=0; i<n; i++)
    {
        int s = jobs[i][0], l = jobs[i][1];
        reqPQ.push({s, l, i});
    }
    
    int curTime = 0;
    while(!reqPQ.empty() || !waitPQ.empty())
    {
        cout << curTime << " \n";
        while(!reqPQ.empty())
        {
            int s, l, i;
            tie(s, l, i) = reqPQ.top();
            if(curTime < s) break;
            reqPQ.pop();
            waitPQ.push({l, s, i});
        }
        if(waitPQ.empty() && !reqPQ.empty())
        {
            int s, l, i;
            tie(s, l, i) = reqPQ.top();
            curTime = s;
            continue;
        }
        
        int l, s, i;
        tie(l, s, i) = waitPQ.top(); waitPQ.pop();
        
        curTime += l;
        answer += (curTime - s);
        cout << i << " " << s << ' ' << curTime << "\n";
    }
    return answer/n;
}