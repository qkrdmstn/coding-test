#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    int sign = 1;
    stringstream ss(my_string);
    string s = "";
    while(ss >> s)
    {
        if(s == "+")
            sign = 1;
        else if(s=="-")
            sign = -1;
        else answer += sign * stoi(s);
    }
    return answer;
}