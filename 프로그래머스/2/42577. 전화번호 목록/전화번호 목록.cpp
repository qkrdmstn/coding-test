#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a.length() > b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    unordered_set<string> s;
    for(auto &str: phone_book)
    {
        string tmp = "";
        if(s.find(str) != s.end())
        {
            answer = false;
            return answer;
        }
        for(int i=0; i<str.length(); i++)
        {
            tmp+=str[i];
            s.insert(tmp);
        }
    }
    return answer;
}