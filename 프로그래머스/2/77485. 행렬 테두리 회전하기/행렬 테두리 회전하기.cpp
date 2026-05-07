#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));
    int num = 1;
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=columns; j++)
        {
            board[i][j] = num;
            num++;
        }
    }
    
    for(auto& q: queries)
    {
        int x1, y1, x2, y2;
        x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        int xDist = x2 - x1;
        int yDist = y2 - y1;
        
        int cx = x1, cy = y1;
        int prev = board[cx][cy];
        int tmp = board[cx][cy];
        int minNum = board[cx][cy];
        
        for(int dir=0; dir<4; dir++)
        {
            int dist = 0;
            if(dir % 2 ==0) dist = yDist;
            else dist = xDist;
            
            for(int i=0; i<dist; i++)
            {
                cx += dx[dir];
                cy += dy[dir];
                
                minNum = min(minNum, board[cx][cy]);
                prev = tmp;
                tmp = board[cx][cy];
                board[cx][cy] = prev;
            }
        }
        answer.push_back(minNum);
    }
    return answer;
}