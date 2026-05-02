#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    unordered_map<int, int> m;
    
    for(string &op:operations)
    {
        stringstream ss(op);
        char opr;
        int num;
        ss >> opr >> num;
        
        if(opr == 'I')
        {
            minHeap.push(num);
            maxHeap.push(num);
            m[num]++;
        }
        else if(opr == 'D')
        {
            if(num == 1 && !maxHeap.empty())
            {
                m[maxHeap.top()]--;
                maxHeap.pop();
            }
            else if(num == -1 && !minHeap.empty())
            {
                m[minHeap.top()]--;
                minHeap.pop();
            }
            while(!maxHeap.empty() && m[maxHeap.top()] <= 0)
                maxHeap.pop();
            while(!minHeap.empty() && m[minHeap.top()] <= 0)
                minHeap.pop();
        }
    }
    if(maxHeap.empty() || minHeap.empty()) answer = {0,0};
    else answer = {maxHeap.top(), minHeap.top()};
    return answer;
}