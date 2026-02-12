#include <string>
#include <vector>
using namespace std;

const string WORDS = "AEIOU";
bool dfs(string cur, const string& target, int& cnt, int& answer)
{
    if(cur == target)
    {
        answer = cnt;
        return true;
    }
    if(cur.length() == 5) return false;

    for(int i=0; i<WORDS.length(); i++)
    {
        cnt++;
        if(dfs(cur + WORDS[i], target, cnt, answer)) return true;
    }
    return false;
}

int solution(string word) {
    int answer = 0;
    int count = 0;
    dfs("", word, count, answer);
    return answer;
}