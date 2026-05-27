#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

void Rotate(deque<char>& dq)
{
    dq.push_back(dq.front());
    dq.pop_front();
}

bool IsPair(char open, char close)
{
    if(open == '(' && close == ')') return true;
    if(open == '{' && close == '}') return true;
    if(open == '[' && close == ']') return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    deque<char> dq;
    for(int i=0; i<len; i++)
        dq.push_back(s[i]);
    
    for(int x=0; x<len; x++)
    {
        stack<char> st;
        
        bool success = true;
        for(int i=0; i<dq.size(); i++)
        {
            char c = dq[i];
            
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if(st.empty())
                {
                    success = false;
                    break;
                }
                if(IsPair(st.top(), c))
                    st.pop();
            }
        }
        if(!st.empty()) success = false;
        if(success) answer++;
        Rotate(dq);
    }
    return answer;
}