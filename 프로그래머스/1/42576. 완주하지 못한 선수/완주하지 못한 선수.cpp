#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> nameCount;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0; i<participant.size(); i++)
        nameCount[participant[i]]++;
    for(int i=0; i<completion.size(); i++)
        nameCount[completion[i]]--;
    for(int i=0; i<participant.size(); i++)
    {
        if(nameCount[participant[i]] != 0)
            answer = participant[i];
    }
    return answer;
}