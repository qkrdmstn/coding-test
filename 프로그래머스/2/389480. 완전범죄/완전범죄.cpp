#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int s = info.size();
    
    //d[i][j]: 아이템 개수가 i개, 남기는 것이 가능한 B의 흔적 개수가 j개일 때 
    //a의 최소 흔적
    vector<vector<int>> d(s+1, vector<int>(m+1, 0));
    for(int i=1; i<=s; i++)
        d[i][0] = d[i-1][0] + info[i-1][0]; //누적, a[i-1]은 i번째 아이템을 의미
    
    for(int i=1; i<=s; i++)
    {
        int curItemIdx = i-1;
        for(int j=1; j<=m; j++)
        {
            if(j < info[curItemIdx][1])
                d[i][j] = d[i-1][j] + info[curItemIdx][0]; //A의 흔적 남기기
            //이번 아이템을 a가 훔치는 것과 b가 훔치는 것 중 a의 흔적이 더 적게 남는 것을 선택
            else
                d[i][j] = min(d[i-1][j-info[curItemIdx][1]], d[i-1][j] + info[curItemIdx][0]);
        }
    }
    //answer = 아이템이 s개, B의 흔적이 m-1개까지 가능한 경우
    answer = d[s][m-1];
    if(answer >= n) answer = -1;
    return answer;
}