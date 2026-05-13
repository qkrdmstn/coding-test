#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void BuildBoard(vector<vector<int>>& rectangle, vector<vector<int>>& board)
{
    for(auto& rect: rectangle)
    {
        int minX = rect[0], minY = rect[1], maxX = rect[2], maxY = rect[3];
        for(int x=minX; x<=maxX; x++)
        {
            for(int y=minY; y<=maxY; y++)
            {
                // 1: 가장자리, 2: 사각형 내부
                if(x > minX && x < maxX && y > minY && y < maxY)
                    board[x][y] = 2;
                else
                {
                    // 다른 사각형의 내부로 이미 매핑되었다면 무시.
                    if(board[x][y] != 2) board[x][y] = 1;
                }
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 선과 면을 구분하기 위해 좌표계 2배 확장
    for(auto& rect: rectangle)
    {
        for(auto& x: rect)
            x *= 2;
    }
    characterX *= 2, characterY *= 2;
    itemX *= 2, itemY *= 2;
    
    // board에 사각형 내부, 가장자리를 표시합니다.
    vector<vector<int>> board(110, vector<int>(110, 0));
    BuildBoard(rectangle, board);

    // BFS를 통해 board에 표시된 가장자리 위치를 순회합니다.
    queue<pair<int, int>> q;
    vector<vector<int>> dist(110, vector<int>(110, -1));
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
    
        if(cur.first == itemX && cur.second == itemY)
            return dist[cur.first][cur.second] / 2; // 두 배 확장한 좌표계를 되돌립니다.

        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            
            q.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    return answer;
}