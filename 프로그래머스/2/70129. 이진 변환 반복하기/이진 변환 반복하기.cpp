#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CountOne(string s)
{
    int cnt = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

string ChangeBinary(int cur)
{
    string res = "";
    while(cur != 0)
    {
        res = to_string(cur % 2) + res;
        cur /= 2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s != "1")
    {
        int cnt = CountOne(s);
        answer[1] += s.length() - cnt;
        answer[0]++;
        s = ChangeBinary(cnt);
    }
    return answer;
}