#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    int tmp;
    
    int mn = 0x3f3f3f3f;
    int mx = -0x3f3f3f3f;
    while(ss >> tmp)
    {
        mn = min(mn, tmp);
        mx = max(mx, tmp);
    }
    answer = to_string(mn) + " " + to_string(mx);
    return answer;
}