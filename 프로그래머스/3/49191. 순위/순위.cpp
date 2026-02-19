#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> board(n+1, vector<bool>(n+1, false));
    for(auto r: results)
        board[r[0]][r[1]] = true; //r[0]가 r[1]을 이김
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(board[i][k] && board[k][j])
                    board[i][j] = true;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        int count = 0;
        for(int j=1; j<=n; j++)
        {
            if(board[i][j] || board[j][i]) //i가 j 한테 이기거나, j가 i한테 이겼다면(i의 승패가 확실한 경우.)
                count++;
        }
        if(count == n-1) //자신을 제외한 모든 사람과의 승패가 확실한 경우 순위를 확정짓는다.
            answer++;
    }
    return answer;
}