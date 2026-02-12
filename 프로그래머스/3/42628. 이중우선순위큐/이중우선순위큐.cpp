#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    unordered_map<int, int> m;
    
    //최소 힙과 최대 힙 각각을 이용하여 최대 최소 값 제거를 진행합니다.
    // 이때, 제거되는 원소는 map 자료구조를 활용해 확인합니다.
    for(int i=0; i<operations.size(); i++)
    {
        stringstream ss(operations[i]);
        string op;
        int num;
        ss >> op >> num;
        
        if(op == "I")
        {
            minPQ.push(num);
            maxPQ.push(num);
            m[num]++;
        }
        else
        {
            if(num == 1 && !maxPQ.empty())
            {
                m[maxPQ.top()]--;
                maxPQ.pop();
            }
            else if(num == -1 && !minPQ.empty())
            {
                m[minPQ.top()]--;
                minPQ.pop();
            }
            
            //map에서 카운트하는 원소 개수가 0이하라면 힙에서 모두 제거합니다.
            while(!minPQ.empty() && m[minPQ.top()] <= 0)
                minPQ.pop();
            while(!maxPQ.empty() && m[maxPQ.top()] <= 0)
                maxPQ.pop();
        }
    }
    
    if(maxPQ.empty() || minPQ.empty()) 
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxPQ.top());
        answer.push_back(minPQ.top());
        
    }
    return answer;
}