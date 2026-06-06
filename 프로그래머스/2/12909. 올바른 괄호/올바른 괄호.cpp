#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    for(const auto& c: s)
    {
        if(c=='(') st.push(c);
        else
        {
            if(!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
            
    }
    
    if(!st.empty()) return false;
    return true;
}