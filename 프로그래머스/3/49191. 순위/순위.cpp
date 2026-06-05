#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> vis(n+1, vector<bool>(n+1, false));
    for(auto const& res: results)
        vis[res[0]][res[1]] = true;

    // 플로이드 워셜 알고리즘을 이용해 모든 승패 관계를 계산합니다.
    for(int k=1; k<=n; k++)
    {
        for(int st=1; st<=n; st++)
        {
            for(int ed=1 ; ed<=n; ed++)
            {
                if(vis[st][k] && vis[k][ed])
                    vis[st][ed] = true;
            }
        }
    }
    
    // 자신을 제외한 나머지 모든 사람과 승패가 결정된 사람은
    // 순위를 계산할 수 있습니다.
    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            if(vis[i][j] || vis[j][i]) cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    return answer;
}