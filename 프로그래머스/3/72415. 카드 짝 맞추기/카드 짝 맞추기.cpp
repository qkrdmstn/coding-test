#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool IsBounded(int x, int y)
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

int BFS(vector<int>& res, int x, int y, vector<vector<int>> board)
{
    int ans = 0;
    pair<int, int> st = {x, y};
    for(auto& target: res)
    {
        //cout << "Target: " << target << "\n";
        int pairCnt = 0;
        while(pairCnt < 2)
        {
            queue<pair<int, int>> q;
            vector<vector<int>> dist(4, vector<int>(4, -1));
            
            // cout << "board:\n";
            // for(int i=0; i<4; i++)
            // {
            //     for(int j=0; j<4; j++)
            //         cout << board[i][j] << " ";
            //     cout << "\n";
            // }
            
            q.push(st);
            dist[st.first][st.second] = 0;
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                if(board[cur.first][cur.second] == target)
                {
                    ans += dist[cur.first][cur.second];
                    ans++;
                    board[cur.first][cur.second] = 0;
                    st = cur;
                    pairCnt++;
                    break;
                }
                
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(!IsBounded(nx, ny)) continue;
                    if(dist[nx][ny] >= 0) continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                }
                
                for(int dir=0; dir<4; dir++)
                {
                    int cx = cur.first, cy = cur.second;
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    while(IsBounded(nx, ny))
                    {
                        cx = nx;
                        cy = ny;
                        if(board[cx][cy] != 0) break;
                        nx += dx[dir];
                        ny += dy[dir];
                    }
                    if(!IsBounded(cx, cy)) continue;
                    if(dist[cx][cy] >= 0) continue;
                    q.push({cx,cy});
                    dist[cx][cy] = dist[cur.first][cur.second] + 1;
                }
            }
            

            // cout << "dist:\n";
            // for(int i=0; i<4; i++)
            // {
            //     for(int j=0; j<4; j++)
            //         cout << dist[i][j] << " ";
            //     cout << "\n";
            // }
            // cout << "ans: " << ans << "\n";
            // cout << "\n";
        }
        
    }
    return ans;
}

void DFS(vector<bool>& used, unordered_set<int>& cards, vector<int>& res, int& ans, int x, int y, vector<vector<int>>& board)
{
    if(res.size() == cards.size())
    {
        cout << "-----------------\n";
        ans = min(ans, BFS(res, x, y, board));
        return;
    }
    for(auto& card: cards)
    {
        if(used[card]) continue;
        used[card] = true;
        res.push_back(card);
        DFS(used, cards, res, ans, x, y, board);
        res.pop_back();
        used[card] = false;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x3f3f3f3f;
    
    unordered_set<int> cards;
    for(int i=0; i<board.size(); i++) 
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] != 0) cards.insert(board[i][j]);
        }
    }
    
    vector<int> res;
    vector<bool> used(7, false);
    DFS(used, cards, res, answer, r, c, board);
    
    return answer;
}