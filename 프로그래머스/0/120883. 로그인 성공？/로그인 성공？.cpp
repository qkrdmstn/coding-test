#include <string>
#include <vector>

using namespace std;

bool IsCorrect(string a, string b)
{
    if(a.length() != b.length()) return false;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}
string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    
    for(int i=0; i<db.size(); i++)
    {
        if(IsCorrect(id_pw[0], db[i][0]))
        {
            answer = "wrong pw";
            if(IsCorrect(id_pw[1], db[i][1]))
                answer = "login";
            break;
        }
    }
    return answer;
}