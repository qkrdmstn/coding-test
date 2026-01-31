#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<bool> flag(128, false);
    
    for(int i=0; i<my_string.length(); i++){
        if(flag[my_string[i]]) continue;
        answer += my_string[i];
        flag[my_string[i]] = true;
        
    }
    return answer;
}