#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(auto& w: works)
        pq.push(w);
    
    for(int i=0; i<n; i++)
    {
        int mx = pq.top();
        pq.pop();
        mx--;
        if(mx < 0)
            mx = 0;
        pq.push(mx);
    }
    
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}