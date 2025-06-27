#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    vector<vector<int>> dp = vector<vector<int>>(info.size() + 1, vector<int>(m));
    
    for(int i=0; i<info.size(); i++){
        answer += info[i][0];
        for(int j=0; j<m; j++){
            dp[i+1][j] = dp[i][j];
            if(j>=info[i][1])
                dp[i+1][j] = max(dp[i][j], dp[i][j-info[i][1]] + info[i][0]);
        }
    }
    
    answer -= dp[info.size()][m-1];
    if(answer >= n) answer = -1;
    return answer;
    
    /*
    knapsak problem 응용
    a의 흔적을 가치, b의 흔적을 무게로 두는 배낭 문제로 추상화하여,
    m만큼의 제한이 있는 가방에 a의 흔적을 최대로 담는 방식으로 dp를 수행.
    
    이후, a의 총합에서 a의 흔적을 빼고 남은 갯수가 최소 흔적의 개수가 된다.
    최소 흔적의 개수가 n 이상이면 -1을 반환하고 아니면 값을 반환한다.
    */
}