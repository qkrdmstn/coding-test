#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> Normalize(vector<pair<int, int>>& shape)
{
    int minX = 150, minY = 150;
    for(auto s: shape)
    {
        minX = min(s.first, minX);
        minY = min(s.second, minY);
    }
    for(auto& s: shape)
    {
        s.first -= minX;
        s.second -= minY;
    }
    sort(shape.begin(), shape.end());
    return shape;
}

vector<pair<int, int>> Rotate(vector<pair<int, int>>& shape)
{
    for(auto& s: shape)
    {
        int temp = s.first;
        s.first = s.second;
        s.second = -temp;
    }
    Normalize(shape);
    return shape;
}

vector<vector<pair<int, int>>> GetShapes(vector<vector<int>>& board, int target)
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<pair<int, int>>> result;    
    vector<vector<bool>> visited(board.size(), vector<bool>(board.size(), false));
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] != target || visited[i][j]) continue;
            vector<pair<int, int>> shape;
            queue<pair<int, int>> q;
            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                shape.push_back(cur);
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) 
                        continue;
                    if(visited[nx][ny] || board[nx][ny] != target) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            result.push_back(Normalize(shape));
        }
    }
    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> holes = GetShapes(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetShapes(table, 1);
    vector<bool> usedBlock(blocks.size(), false);
    
    for(auto hole: holes)
    {
        bool found = false;
        for(int i=0; i<blocks.size(); i++)
        {
            if(hole.size() != blocks[i].size() || usedBlock[i]) continue;
            for(int j=0; j<4; j++)
            {
                if(hole == blocks[i])
                {
                    answer += blocks[i].size();
                    usedBlock[i] = true;
                    found = true;
                    break;
                }
                Rotate(blocks[i]);
            }
            if(found) break;
        }
    }
    return answer;
}