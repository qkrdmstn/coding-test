#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    for(int i=0; i<str1.length(); i++){
        int cnt = 0;
        for(int j=0; j<str2.length(); j++){
            if(str1[i] == str2[j]){
                cnt++;
                i++;                
            }
            else break;
        }
        if(cnt == str2.length()){
            answer = 1;
            break;            
        }
    }
    return answer;
}