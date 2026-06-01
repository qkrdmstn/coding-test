#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<pair<int, int>> Normalize(vector<pair<int, int>>& block)
{
    int minX = block[0].first, minY = block[0].second;
    for(const auto& pos: block)
    {
        minX = min(pos.first, minX);
        minY = min(pos.second, minY);
    }
    
    for(auto& pos: block)
    {
        pos.first -= minX;
        pos.second -= minY;
    }
    sort(block.begin(), block.end());
    return block;
}

vector<pair<int, int>> Rotate(vector<pair<int, int>>& block)
{
    for(auto& pos: block)
    {
        int tmp = pos.first;
        pos.first = pos.second;
        pos.second = -tmp;
    }
    return Normalize(block);
}

vector<vector<pair<int, int>>> GetBlocks(vector<vector<int>>& board, int target)
{
    int n = board.size();
    vector<vector<pair<int, int>>> blocks;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vis[i][j] || board[i][j] != target) continue;
            q.push({i, j});
            vis[i][j] = true;
            vector<pair<int, int>> block;
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                block.push_back(cur);
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
            blocks.push_back(Normalize(block));
        }
    }
    return blocks;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> cells = GetBlocks(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetBlocks(table, 1);
    vector<bool> usedBlock(blocks.size(), false);
    
    for(const auto& hole: cells)
    {
        bool isFind = false;
        for(int i=0; i<blocks.size(); i++)
        {
            if(usedBlock[i] || hole.size() != blocks[i].size()) continue;
            vector<pair<int, int>> curBlock = blocks[i];
            
            for(int rot=0; rot<4; rot++)
            {
                if(hole == curBlock)
                {
                    usedBlock[i] = true;
                    isFind = true;
                    answer += blocks[i].size();
                    break;
                }
                
                curBlock = Rotate(curBlock);
            }
            if(isFind) break;
        }
    }
    return answer;
}