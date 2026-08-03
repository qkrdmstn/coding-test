#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<pair<int, int>> Normalize(vector<pair<int, int>>& block)
{
    int minX = 51, minY = 51;
    for(const auto& b: block)
    {
        minX = min(b.first, minX);
        minY = min(b.second, minY);
    }
    
    for(auto& b: block)
    {
        b.first -= minX;
        b.second -= minY;
    }
    sort(block.begin(), block.end());
    return block;
}

vector<pair<int, int>> Rotate(vector<pair<int, int>>& block)
{
    for(auto& b: block)
    {
        int tmp = b.first;
        b.first = b.second;
        b.second = -tmp;
    }
    return Normalize(block);
}

vector<vector<pair<int, int>>> GetBlocks(vector<vector<int>> board, int target)
{
    int n = board.size();
    
    vector<vector<pair<int, int>>> blocks;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j] != target || vis[i][j]) continue;
            
            queue<pair<int, int>> q;
            vector<pair<int, int>> block;
            
            q.push({i, j});
            vis[i][j] = true;
            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                block.push_back(cur);
                
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != target || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            
            blocks.push_back(Normalize(block));
        }
    }
    
    return blocks;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> holes = GetBlocks(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetBlocks(table, 1);
    
    vector<bool> usedBlock(blocks.size(), false);
    
    for(const auto& h: holes)
    {
        bool isFind = false;
        for(int i=0; i<blocks.size(); i++)
        {
            vector<pair<int, int>> curBlock = blocks[i];
            if(usedBlock[i] || h.size() != curBlock.size()) continue;
            
            for(int r=0; r<4; r++)
            {
                if(curBlock == h)
                {
                    isFind = true;
                    answer += curBlock.size();
                    usedBlock[i] = true;
                    break;
                }
                curBlock = Rotate(curBlock);
            }
            if(isFind) break;
        }
    }
    return answer;
}