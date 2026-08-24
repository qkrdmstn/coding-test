#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(const auto& q: quiz)
    {
        stringstream ss(q);
        int a, b, res;
        char op, equal;
        ss >> a >> op >> b >> equal >> res;
        
        if(op == '+')
        {
            if(a+b == res) answer.push_back("O");
            else answer.push_back("X");
        }
        else
        {
            if(a-b == res) answer.push_back("O");
            else answer.push_back("X");
        }
    }
    
    
    return answer;
}