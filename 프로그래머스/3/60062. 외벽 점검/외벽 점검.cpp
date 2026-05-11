#include <string>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int foo(vector<int>& dist, vector<int>& weak)
{
    int ans = INF;
    for(int s=0; s<weak.size()/2; s++)
    {
        int friendIdx = 0;
        int finishLine = weak[s] + dist[friendIdx];
        for(int i=s; i<s+weak.size()/2; i++)
        {
            if(finishLine < weak[i])
            {
                friendIdx++;
                if(friendIdx >= dist.size()) break;
                finishLine = weak[i] + dist[friendIdx];
            }
        }
        if(friendIdx != dist.size())
            ans = min(ans, friendIdx + 1);
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
        DFS(used, dist, res, weak, ans);
        res.pop_back();
        used[i] = false;
    }
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    
    int sz = weak.size();
    for(int i=0; i<sz; i++)
        weak.push_back(weak[i] + n);
    
    vector<int> res;
    vector<bool> used(dist.size(), false);
    DFS(used, dist, res, weak, answer);
    
    if(answer == INF) return -1;
    return answer;
}