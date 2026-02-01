#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    string s = "";
    for(int idx=i; idx<=j; idx++)
        s += to_string(idx);
    for(int idx=0; idx<s.length(); idx++)
    {
        if(s[idx] == k + '0')
            answer++;
    }
    return answer;
}