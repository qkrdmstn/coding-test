#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int pickCount = number.length() - k;
    
    int lastPickIdx = -1;
    while(pickCount)
    {
        int maxIdx = lastPickIdx + 1;
        for(int i=lastPickIdx + 1; i<=number.length()-pickCount; i++)
        {
            if(number[i] > number[maxIdx])
                maxIdx = i;
        }
        lastPickIdx = maxIdx;
        answer += number[maxIdx];
        pickCount--;
    }
    return answer;
}