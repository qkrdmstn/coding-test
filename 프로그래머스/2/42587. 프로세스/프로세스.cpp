#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    vector<int> orderedPriorities;
    for(int i=0; i<priorities.size(); i++)
    {
        q.push({priorities[i], i});
        orderedPriorities.push_back(priorities[i]);
    }
    sort(orderedPriorities.begin(), orderedPriorities.end(), greater<int>());
    
    for(int i=0; i<orderedPriorities.size(); i++)
    {
        while(q.front().first != orderedPriorities[i])
        {
            q.push(q.front());
            q.pop();
        }
        answer++;
        if(q.front().second == location) break;
        q.pop();
    }
    return answer;
}