#include <string>
#include <vector>

using namespace std;

// 누적 합 기법을 통해 모든 연산을 줄일 수 있다.
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
    
    for(const auto& s: skill)
    {
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];
        if(s[0] == 1) degree *= -1;
        
        diff[r1][c1] += degree;
        diff[r2+1][c1] -= degree;
        diff[r1][c2+1] -= degree;
        diff[r2+1][c2+1] += degree;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            diff[i][j+1] += diff[i][j];
    }
    
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
            diff[i+1][j] += diff[i][j];
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] + diff[i][j] > 0) answer++;
        }
    }
    return answer;
}