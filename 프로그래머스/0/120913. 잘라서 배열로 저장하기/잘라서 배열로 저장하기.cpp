#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;

    int idx = 0;
    int cnt = 0;
    string s="";
    while(idx < my_str.length())
    {
        
        if(cnt >= n)
        {
            answer.push_back(s);
            cnt = 0;
            s = "";
        }
        s+=my_str[idx];
        idx++;
        cnt++;
    }
    answer.push_back(s);
    return answer;
}