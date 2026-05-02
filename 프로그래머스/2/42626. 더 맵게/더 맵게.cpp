#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto &s: scoville)
        pq.push(s);

    while(pq.size() >= 2 && pq.top() < K)
    {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int res = first + (second * 2);
        pq.push(res);
        answer++;
    }
    if(pq.top() >= K) return answer;
    else return -1;
}