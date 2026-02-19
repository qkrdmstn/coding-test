#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


void BuildBoard(vector<vector<int>>& board, vector<vector<int>>& rectangle)
{
    for(auto& r: rectangle)
    {
        int minX = r[0], minY = r[1], maxX = r[2], maxY = r[3];
        for(int x=minX; x<=maxX; x++)
        {
            for(int y=minY; y<=maxY; y++)
            {
                if(x > minX && x < maxX && y > minY && y < maxY)
                    board[x][y] = 2; //내부
                else{
                    if(board[x][y] != 2) //다른 사각형의 내부면 제외
                        board[x][y] = 1; //테두리
                }
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    //면과 선을 구분하기 위해 좌표계를 2배 확장합니다.
    for(auto& r: rectangle){
        for(int& val: r) val*=2;
    }
    characterX *=2; characterY *=2;
    itemX *= 2; itemY *= 2;
    
    //보드 채우기
    vector<vector<int>> board(110, vector<int>(110));
    vector<vector<int>> dist(110, vector<int>(110, -1));
    BuildBoard(board, rectangle);

    //BFS
    queue<pair<int, int>> q;
    q.push({characterX,characterY});
    dist[characterX][characterY] = 0;
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        if(curX == itemX && curY == itemY) return dist[curX][curY] / 2;
        for(int dir=0; dir<4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[curX][curY] + 1;
            q.push({nx, ny});
            
        }
    }
    
    return 0;
}