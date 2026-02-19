#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> Normalize(vector<pair<int, int>> shape)
{
    int minX = 105, minY = 105;
    for(auto s: shape)
    {
        minX = min(minX, s.first);
        minY = min(minY, s.second);
    }
    for(auto &s: shape)
    {
        s.first -= minX;
        s.second -= minY;
    }
    sort(shape.begin(), shape.end());
    return shape;
}

vector<pair<int, int>> Rotate(vector<pair<int, int>> shape)
{
    for(auto &s: shape)
    {
        int tmp = s.first;
        s.first = s.second;
        s.second = -tmp;
    }
    return Normalize(shape);
}

vector<vector<pair<int, int>>> GetShapes(vector<vector<int>> board, int target)
{
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), false));
    vector<vector<pair<int, int>>> results;
    
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
                    if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) continue;
                    if(visited[nx][ny] || board[nx][ny] != target) continue;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            results.push_back(Normalize(shape));
        }
    }
    
    return results;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> holes = GetShapes(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetShapes(table, 1);
    vector<bool> usedBlock(blocks.size(), false);
    
    for(auto &hole: holes)
    {
        bool found = false;
        for(int i=0; i<blocks.size(); i++)
        {
            if(usedBlock[i] || hole.size() != blocks[i].size()) continue;
            vector<pair<int, int>> curBlock = blocks[i];
            
            for(int r=0; r<4; r++)
            {
                if(hole == curBlock)
                {
                    answer += hole.size();
                    usedBlock[i] = true;
                    found = true;
                    break;
                }
                curBlock = Rotate(curBlock);
            }
            if(found) break;
        }
    }
    
    return answer;
}