#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    for(int i=0; i<priorities.size(); i++)
        dq.push_back({priorities[i], i});

    while(!dq.empty())
    {
        int cur = dq.front().first;
        bool flag = true;
        for(int i=1; i<dq.size(); i++)
        {
            if(cur < dq[i].first)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                flag = false;
                break;
            }
        }
        if(flag)
        {
            answer++;
            if(dq.front().second == location)
                return answer;
            dq.pop_front();
        }
    }
    return answer;
}