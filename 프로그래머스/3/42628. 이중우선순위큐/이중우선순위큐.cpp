#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    unordered_map<int, int> m;
    for(const string& operation: operations)
    {
        stringstream ss(operation);
        char op;
        int num;
        ss >> op >> num;
        
        if(op == 'I')
        {
            maxHeap.push(num);
            minHeap.push(num);
            m[num]++;
        }
        else if(op == 'D')
        {
            if(num == -1 && !minHeap.empty())
            {
                m[minHeap.top()]--;
                minHeap.pop();
            }
            else if(num == 1 && !maxHeap.empty())
            {
                m[maxHeap.top()]--;
                maxHeap.pop();
            }
        }
        
        while(!maxHeap.empty() && m[maxHeap.top()] <= 0)
            maxHeap.pop();
        while(!minHeap.empty() && m[minHeap.top()] <= 0)
            minHeap.pop();
    }
    
    if(maxHeap.empty() || minHeap.empty()) answer = {0,0};
    else answer = {maxHeap.top(), minHeap.top()};
    return answer;
}