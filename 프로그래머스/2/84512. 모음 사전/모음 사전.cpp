#include <string>
#include <vector>
#include <iostream>

using namespace std;

string s = "AEIOU";
bool DFS(string cur, int& cnt, string& target, int& ans)
{
    if(cur == target)
    {
        ans = cnt;
        return true;
    }
    
    if(cur.length() == 5) return false;
    for(const auto& c: s)
    {
        cnt++;
        if(DFS(cur + c, cnt, target, ans)) return true;
    }
    return false;
}

int solution(string word) {
    int answer = -1;
    int cnt = 0;
    DFS("", cnt, word, answer);
    return answer;
}