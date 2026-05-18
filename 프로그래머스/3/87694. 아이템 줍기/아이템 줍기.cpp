#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> BuildBoard(vector<vector<int>>& rectangle)
{
    vector<vector<int>> board(110, vector<int>(110, 0));
    for(auto& r: rectangle)
    {
        int minX = r[0], minY = r[1];
        int maxX = r[2], maxY = r[3];
        for(int x = minX; x<=maxX; x++)
        {
            for(int y=minY; y<=maxY; y++)
            {
                // 사각형 내부
                if(x > minX && x < maxX && y > minY && y < maxY)
                    board[x][y] = 2;
                // 사각형 가장자리
                else
                {
                    // 다른 사각형의 내부가 아니면 가장자리로 처리 (1)
                    if(board[x][y] != 2) board[x][y] = 1;
                }
            }
        }
    }
    return board;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 점과 선을 구분하기 위해 모든 좌표계를 2배 늘립니다.
    characterX *= 2, characterY *= 2;
    itemX *= 2, itemY *= 2;
    for(auto& rect: rectangle)
    {
        for(auto& r: rect)
            r *= 2;
    }
    // 주어진 사각형의 내부와 외부를 구분하여 플레이어가 이동한 길을 표시합니다.
    vector<vector<int>> board = BuildBoard(rectangle);
    // for(int i=0; i<30; i++)
    // {
    //     for(int j=0; j<30; j++)
    //         cout << board[i][j] << " ";
    //     cout << "\n";
    // }
    
    // BFS 알고리즘을 이용해 플레이어의 이동을 시뮬레이션합니다.
    queue<pair<int, int>> q;
    vector<vector<int>> dist(110, vector<int>(110, -1));
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        // 목표 지점에 도달한 경우
        if(cur.first == itemX && cur.second == itemY)
        {
            answer = dist[itemX][itemY]/2;
            break;
        }
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
            if(board[nx][ny] != 1 || dist[nx][ny] >= 0) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
     
    return answer;
}