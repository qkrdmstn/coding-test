#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> Normalize(vector<pair<int, int>>& block)
{
    int minX = 51, minY = 51;
    for(const auto& pos : block)
    {
        minX = min(minX, pos.first);
        minY = min(minY, pos.second);
    }
    for(auto& pos : block)
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
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vis[i][j] || board[i][j] != target) continue;
            
            vector<pair<int, int>> block;
            q.push({i, j});
            vis[i][j] = true;
            while(!q.empty())
            {
                auto cur = q.front();
                block.push_back(cur);
                q.pop();
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
    
    vector<vector<pair<int, int>>> blanks = GetBlocks(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetBlocks(table, 1);
    
    
    vector<bool> usedBlock(blocks.size(), false);
    for(const auto& blank: blanks)
    {
        bool isFind = false;
        for(int i=0; i<blocks.size(); i++)
        {
            if(usedBlock[i]) continue;
            if(blank.size() != blocks[i].size()) continue;
            
            for(int rot=0; rot<4; rot++)
            {
                if(blank == blocks[i])
                {
                    usedBlock[i] = true;
                    isFind = true;
                    answer += blocks[i].size();
                    break;
                }
                blocks[i] = Rotate(blocks[i]);
            }
            if(isFind) break;
        }
    }
    
    return answer;
}