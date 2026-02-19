#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[205];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> edge[205];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j) continue;
            if(computers[i][j])
                edge[i].push_back(j);
        }
    }
    
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
            for(auto nxt: edge[cur])
            {
                if(visited[nxt]) continue;
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
    return answer;
}