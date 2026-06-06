#include <string>
#include <vector>
#include <queue>
using namespace std;

int CountTop(int start, int cut, vector<vector<int>>& wires, int n)
{
    queue<int> q;
    vector<bool> vis(n+1, false);
    q.push(start);
    
    vis[start] = true;
    int cnt = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        cnt++;
        for(int i=0; i<wires.size(); i++)
        {
            int nxt = -1;
            if(i==cut) continue;
            if(cur == wires[i][0])
                nxt = wires[i][1];
            if(cur == wires[i][1])
                nxt = wires[i][0];
            if(vis[nxt] || nxt == -1) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n+1;
    
    for(int i=0; i<wires.size(); i++)
    {
        int a = CountTop(wires[i][0], i, wires, n);
        int b = CountTop(wires[i][1], i, wires, n);
        answer = min(abs(a-b), answer);
    }
    return answer;
}