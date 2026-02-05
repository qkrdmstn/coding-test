#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> select1 = {1,2,3,4,5};
    vector<int> select2 = {2,1,2,3,2,4,2,5};
    vector<int> select3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> cnt = {0,0,0};
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == select1[i%select1.size()])
            cnt[0]++;
        if(answers[i] == select2[i%select2.size()])
            cnt[1]++;
        if(answers[i] == select3[i%select3.size()])
            cnt[2]++;
    }
    
    int maxCnt = cnt[0];
    for(int i=1; i<3; i++)
    {
        if(maxCnt < cnt[i]) maxCnt = cnt[i];
    }
    for(int i=0; i<3; i++)
    {
        if(maxCnt == cnt[i]) answer.push_back(i+1);
    }
    
    return answer;
}