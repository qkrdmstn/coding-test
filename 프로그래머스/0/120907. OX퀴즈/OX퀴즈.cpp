#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(const string& q: quiz)
    {
        stringstream ss(q);
        int x, y, z;
        char op, equal;
        ss >> x >> op >> y >> equal >> z;
        // 연산자가 -라면 y의 부호를 변경 (덧셈 연산으로 통일)
        if(op == '-')
            y *= -1;

        if(x+y == z) answer.push_back("O");
        else answer.push_back("X");
    }
    return answer;
}