#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int, int>> Normalize(vector<pair<int, int>>& block)
{
    int minX = block[0].first, minY = block[0].second;
    for(auto& pos: block)
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
    Normalize(block);
    return block;
}

vector<vector<pair<int, int>>> GetBlocks(vector<vector<int>>& board, int target)
{
    vector<vector<pair<int, int>>> blocks;
    
    int n = board.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vis[i][j] || board[i][j] != target) continue;
            queue<pair<int, int>> q;
            vector<pair<int, int>> block;
            
            q.push({i, j});
            vis[i][j] = true;
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
    vector<vector<pair<int, int>>> blanks = GetBlocks(game_board, 0);
    vector<vector<pair<int, int>>> blocks = GetBlocks(table, 1);
    
    vector<bool> usedBlock(blocks.size(), false);
    
    for(auto& blank: blanks)
    {
        bool isFound = false;
        for(int i=0; i<blocks.size(); i++)
        {
            if(usedBlock[i]) continue;
            if(blank.size() != blocks[i].size()) continue;
            for(int rot=0; rot<4; rot++)
            {
                if(blank == blocks[i])
                {
                    answer += blocks[i].size();
                    usedBlock[i] = true;
                    isFound = true;
                    break;
                }
                Rotate(blocks[i]);
            }
            if(isFound) break;
        }
    }
    

    return answer;
}