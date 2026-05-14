#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(string letter) {
    string answer = "";
    unordered_map<string, char> morse = { 
        {".-", 'a'}, {"-...",'b'},{"-.-.",'c'},{"-..",'d'},{".",'e'},{"..-.",'f'},
        {"--.",'g'},{"....",'h'},{"..",'i'},{".---",'j'},{"-.-",'k'},{".-..",'l'},
        {"--",'m'},{"-.",'n'},{"---",'o'},{".--.",'p'},{"--.-",'q'},{".-.",'r'},
        {"...",'s'},{"-",'t'},{"..-",'u'},{"...-",'v'},{".--",'w'},{"-..-",'x'},
        {"-.--",'y'},{"--..",'z'}
    };
    
    stringstream ss(letter);
    string s;
    while(ss >> s)
        answer.push_back(morse[s]);
    return answer;
}