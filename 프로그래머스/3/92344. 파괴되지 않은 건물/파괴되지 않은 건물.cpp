#include <string>
#include <vector>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    // 2차원 누적합 기법을 통해 공격/회복을 표현합니다.
    vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
    for(const auto& s: skill)
    {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = ((type == 1) ? -s[5] : s[5]);
        
        arr[r1][c1] += degree;
        arr[r1][c2+1] -= degree;
        arr[r2+1][c1] -= degree;
        arr[r2+1][c2+1] += degree;
    }
    
    // 누적 합 계산 (가로/세로 방향 누적)
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<m; c++)
            arr[r+1][c] += arr[r][c];
    }
    for(int c=0; c<m; c++)
    {
        for(int r=0; r<n; r++)
            arr[r][c+1] += arr[r][c];
    }
    
    // 초기 값과 누적 합 값을 합해 파괴되지 않은 건물 개수를 구합니다.
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<m; c++)
        {
            if(board[r][c] + arr[r][c] > 0) 
                answer++;
        }
    }
    return answer;
}