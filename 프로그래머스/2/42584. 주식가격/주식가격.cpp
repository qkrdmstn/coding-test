#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    stack<pair<int, int>> s;
    for(int i=0; i<prices.size(); i++)
    {
        while(!s.empty() && s.top().first > prices[i])
        {
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({prices[i], i});
    }
    
    while(!s.empty())
    {
        answer[s.top().second] = prices.size() - s.top().second - 1;
        s.pop();
    }
    return answer;
}