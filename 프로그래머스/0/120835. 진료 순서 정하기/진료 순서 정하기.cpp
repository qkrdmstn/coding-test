#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    vector<int> sortedEmergency(emergency);
    sort(sortedEmergency.begin(), sortedEmergency.end(), greater<int>());
    
    for(int i=0; i<emergency.size(); i++)
    {
        for(int j=0; j<sortedEmergency.size(); j++)
        {
            if(emergency[i] == sortedEmergency[j])
            {
                answer.push_back(j + 1);
                break;
            }
        }
    }
    return answer;
}