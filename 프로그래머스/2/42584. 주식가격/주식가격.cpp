#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();

    vector<int> answer(n);
    stack<pair<int, int>> st; // {가격, 시간}
    
    // 이전 가격이 현재 가격보다 높을 경우 가격이 떨어진 것이므로 스택에서 제거합니다.
    for(int i=0; i<prices.size(); i++)
    {
        int price = prices[i];
        
        // 스택의 top에 있는 가격보다 현재 가격이 낮다면 최초로 가격이 떨어진 시점입니다.
        while(!st.empty() && st.top().first > price)
        {
            // 가격이 떨어지지 않은 시간을 기록합니다.
            answer[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({price, i});
    }
    
    // 끝까지 가격이 떨어지지 않은 가격들을 제거합니다.
    while(!st.empty())
    {
        answer[st.top().second] = (n-1) - st.top().second;
        st.pop();
    }
    return answer;
}