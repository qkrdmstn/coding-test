#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// 사각형들의 좌표를 바탕으로 맵에 다각형의 테두리를 구분합니다.
vector<vector<int>> BuildBoard(vector<vector<int>>& rectangle)
{
    // 좌표 확장을 고려해 150x150 크기로 맵을 설정합니다.
    vector<vector<int>> board(150, vector<int>(150, 0));
            
    for(auto& rect: rectangle)
    {
        int minX = rect[0], minY = rect[1];
        int maxX = rect[2], maxY = rect[3];
        for(int x=minX; x<=maxX; x++)
        {
            for(int y=minY; y<=maxY; y++)
            {
                // 다른 사각형의 내부로 판정된 영역은 다각형의 테두리가 될 수 없습니다.
                if(board[x][y] == 2) continue;
                
                // 현재 사각형의 가장자리는 테두리 후보(1), 내부(2)로 마킹합니다.
                if(x == minX || x == maxX || y == minY || y == maxY)
                    board[x][y] = 1;
                else
                    board[x][y] = 2;
            }
        }
    }
    return board;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 점과 선을 구분하기 위해 좌표계를 2배 늘립니다.
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    for(auto& rect: rectangle)
    {
        for(int i=0; i<4; i++)
            rect[i] *= 2;
    }

    // 맵을 구축하고, BFS를 통해 테두리(1)만 타고 이동하는 item에 도달하는 최단 거리를 구합니다.
    vector<vector<int>> board = BuildBoard(rectangle);
    vector<vector<int>> dist(150, vector<int>(150, -1));
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        // 아이템 이치에 도달하면 탐색을 종료합니다.
        if(cur.first == itemX && cur.second == itemY)
        {
            // 2배 확장된 좌표계에서 원본 스케일로 복구합니다.
            return dist[cur.first][cur.second] / 2;
        }
        
        for(int dir=0;dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // 2배 확장된 사각형들의 최대 좌표 범위를 고려하여 경계를 확인합니다.
            if(nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
            // 미방문 지역이면서 테두리인 경로만 방문 가능합니다.
            if(dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}