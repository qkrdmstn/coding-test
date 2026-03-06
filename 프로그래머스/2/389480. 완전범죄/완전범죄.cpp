#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int itemSize = info.size();
    
    //d[i][j]: 아이템이 i개, B의 사용 가능 흔적이 j개일 때 a의 최소 누적 흔적
    vector<vector<int>> d(itemSize + 1, vector<int>(m, 0));
    
    //B의 사용 가능 흔적이 0이면 a의 흔적 남기기
    for(int i=1; i<=itemSize; i++)
        d[i][0] = d[i-1][0] + info[i-1][0];
    
    for(int i=1; i<= itemSize; i++)
    {
        for(int j=1; j< m; j++)
        {
            //B의 흔적이 초과라면 a의 흔적을 남겨야 한다.
            if(j < info[i-1][1])
                d[i][j] = d[i-1][j] + info[i-1][0];
            //a의 흔적을 남길지 b의 흔적일 남길지 최소인 것을 선택
            else
                d[i][j] = min(d[i-1][j - info[i-1][1]], d[i-1][j] + info[i-1][0]);
        }
    }
    
    if(d[itemSize][m-1] >= n) answer = -1;
    else answer= d[itemSize][m-1];
    return answer;
}