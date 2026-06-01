#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 17;
int func(vector<int>& dist, vector<int>& weak)
{
    int ans = INF;
    for(int st=0; st<weak.size()/2; st++)
    {
        int friendIdx = 0;
        int cur = weak[st] + dist[friendIdx];
        for(int i=st; i<st + weak.size()/2; i++)
        {
            if(cur < weak[i])
            {
                friendIdx++;
                if(friendIdx >= dist.size()) break;
                cur = weak[i] + dist[friendIdx];
            }
        }
        if(friendIdx != dist.size())
            ans = min(friendIdx+1, ans);
    }
    return ans;
}

void DFS(vector<bool>& used, vector<int>& dist, vector<int>& res, vector<int>& weak, int& ans)
{
    if(res.size() == dist.size())
    {
        ans = min(func(res, weak), ans);
        return;
    }
    
    for(int i=0; i<dist.size(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        res.push_back(dist[i]);
        DFS(used, dist, res, weak, ans);
        res.pop_back();
        used[i] = false;
    }
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    
    int weakNum = weak.size();
    for(int i=0; i<weakNum; i++)
        weak.push_back(weak[i]+n);
    
    vector<int> res;
    vector<bool> used(dist.size(), false);
    DFS(used, dist, res, weak, answer);
    
    if(answer == INF) return -1;
    return answer;
}