#include <string>
#include <vector>
#include <iostream>
using namespace std;

int foo(vector<int>& dist, vector<int>& weak)
{
    int ans = 0x3f3f3f3f;
    for(int s = 0; s < 15; s++)
    {
        int cnt = 0;
        int idx = s;
        int cur = weak[idx];
        for(int i=0; i<dist.size(); i++)
        {
            int end = cur + dist[i];
            while(weak[idx] <= end && idx < weak.size())
            {
                idx++;
                cnt++;            
            }
            cur = weak[idx];
            
            if(cnt >= weak.size()/2)
                ans = min(ans, i+1);
        }
    }
    
    return ans;
}

void DFS(vector<bool>& used, vector<int>& dist, vector<int>& res, vector<int>& weak, int& ans)
{
    if(res.size() == dist.size())
    {
        ans = min(ans, foo(res, weak));
        return;
    }
    
    for(int i=0; i<dist.size(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        res.push_back(dist[i]);
        DFS(used,dist,res,weak, ans);
        res.pop_back();
        used[i] = false;
    }
    
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0x3f3f3f3f;
    
    int sz = weak.size();
    for(int i=0; i<sz; i++)
        weak.push_back(weak[i] + n);

    vector<bool> used(dist.size(), false);
    vector<int> res;
    DFS(used,dist,res,weak, answer);
    if(answer == 0x3f3f3f3f) return -1;
    return answer;
}