#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<pair<int, int>> sumIndexVector;
    for(int i=0; i<score.size(); i++)
    {
        int sum = score[i][0] + score[i][1];
        sumIndexVector.push_back({sum, i});
        answer.push_back(0);
    }
    sort(sumIndexVector.begin(), sumIndexVector.end(), greater<pair<int, int>>());
    
    int cnt=1;
    for(int i=0; i<sumIndexVector.size(); i++)
    {
        int idx = sumIndexVector[i].second;
        if(i != 0 && sumIndexVector[i].first == sumIndexVector[i-1].first)
            answer[idx] = cnt;
        else
        {
            cnt = i + 1;
            answer[idx] = cnt;
        }
    }
    
    return answer;
}