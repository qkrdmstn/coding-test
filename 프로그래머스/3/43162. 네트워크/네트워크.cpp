#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, false);

    for(int i=0; i<n; i++)
    {
        queue<int> q;
        if(!visited[i])
        {
            q.push(i);
            visited[i] = true;
            answer++;
        }
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int nxt=0; nxt<n; nxt++)
            {
                if(cur == nxt || computers[cur][nxt] == 0) continue;
                if(visited[nxt]) continue;
                
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
    return answer;
}