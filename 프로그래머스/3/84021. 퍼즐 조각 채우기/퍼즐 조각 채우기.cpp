#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void Normalize(vector<pair<int, int>>& shape)
{
    int minX = 51, minY = 51;
    for(auto& s: shape)
    {
        minX = min(minX, s.first);
        minY = min(minY, s.second);
    }
    
    for(auto& s: shape)
    {
        s.first -= minX;
        s.second -= minY;
    }
    sort(shape.begin(), shape.end());
}

void Rotate(vector<pair<int, int>>& shape)
{
    for(auto& s: shape)
    {
        int tmp = s.first;
        s.first = s.second;
        s.second = -tmp;
    }
    Normalize(shape);
}

vector<vector<pair<int, int>>> GetShapes(vector<vector<int>>& board, int target)
{
    vector<vector<pair<int, int>>> shapes;
    vector<vector<bool>> vis(board.size(), vector<bool>(board.size(), false));
    int n = board.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vis[i][j] || board[i][j] != target) continue;
            vector<pair<int, int>> shape;
            queue<pair<int, int>> q;
            
            q.push({i, j});
            vis[i][j] = true;
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                shape.push_back(cur);
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || board[nx][ny] != target) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            Normalize(shape);
            shapes.push_back(shape);
        }
    }
    return shapes;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> holes = GetShapes(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetShapes(table, 1);
    
    cout << holes.size() << " " << blocks.size();
    vector<bool> usedBlock(blocks.size(), false);

    for(auto& hole: holes)
    {
        bool isFind = false;
        for(int i=0; i<blocks.size(); i++)
        {
            for(int rot=0; rot<4; rot++)
            {
                if(hole.size() != blocks[i].size() || usedBlock[i]) continue;
                if(hole == blocks[i])
                {
                    isFind = true;
                    usedBlock[i] = true;
                    answer += blocks[i].size();
                    break;
                }
                Rotate(blocks[i]);
            }
            if(isFind) break;
        }
    }
    return answer;
}