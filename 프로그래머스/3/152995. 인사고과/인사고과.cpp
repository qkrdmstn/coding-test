#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    pair<int, int> targetScore = {scores[0][0], scores[0][1]};
    int targetSum = scores[0][0] + scores[0][1];
    
    sort(scores.begin(), scores.end(), cmp);
    
    vector<int> validSum;
    int maxScore = 0;
    for(auto& score: scores)
    {
        if(score[1] < maxScore)
        {
            if(score[0] == targetScore.first && score[1] == targetScore.second) return -1;
            continue;
        }
        
        maxScore = max(score[1], maxScore);
        validSum.push_back(score[0] + score[1]);
    }
    
    sort(validSum.begin(), validSum.end(), greater<int>());
    int answer = lower_bound(validSum.begin(), validSum.end(), targetSum, greater<int>()) - validSum.begin();
    return answer + 1;
}