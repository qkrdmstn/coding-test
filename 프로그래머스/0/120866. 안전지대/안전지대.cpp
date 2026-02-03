#include <string>
#include <vector>

using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] != 1) continue;
            for(int nxt = 0; nxt<8; nxt++)
            {
                int nx = i + dx[nxt];
                int ny = j + dy[nxt];
                //board 범위 확인
                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[i].size())
                    continue;
                if(board[nx][ny] == 1) continue;
                board[nx][ny] = 2;
            }
        }
    }
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 0) answer++;
        }
    }
    return answer;
}