#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, char> m;
string morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
				      ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                      "...","-","..-","...-",".--","-..-","-.--","--.."};
    
string solution(string letter) {
    string answer = "";
    string str ="";
    stringstream ss(letter);
    
    for(int i=0; i<26; i++)
        m[morse[i]] = i+'a';
    
    while(ss>>str)
        answer += m[str];
    
    return answer;
}