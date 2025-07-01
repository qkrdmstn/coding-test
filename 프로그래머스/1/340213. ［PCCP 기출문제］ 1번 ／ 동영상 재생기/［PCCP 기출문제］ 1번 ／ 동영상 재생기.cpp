#include <string>
#include <vector>
#include <iostream>
using namespace std;

int StrToInt(string s)
{
    int num = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ':') continue;
        num *= 10;
        num += s[i] - '0';
    }    
    return num;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int len = StrToInt(video_len);
    int curPos = StrToInt(pos);
    int opStart = StrToInt(op_start);
    int opEnd = StrToInt(op_end);
    
    for(int i=0; i<commands.size(); i++){
        if(curPos >= opStart && curPos <= opEnd)
            curPos = opEnd;
        if(commands[i] == "prev"){
            if(curPos % 100 < 10) curPos -= 40;
            curPos -= 10;
            if(curPos < 0) curPos = 0;
        }
        else if(commands[i] == "next"){
            if(curPos % 100 > 49) curPos += 40;
            curPos += 10;
            if(curPos > len) curPos = len;
        }
        if(curPos >= opStart && curPos <= opEnd)
            curPos = opEnd;
    }
    int m = curPos / 100;
    int s = curPos % 100;
    if(m < 10) answer += "0";
    answer += to_string(m);
    answer += ":";
    if(s<10) answer += "0";
    answer += to_string(s);
    return answer;
}