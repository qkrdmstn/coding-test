#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

bool IsBounded(int r, int c)
{
    return (r >= 0 && r <= 3 && c >= 0 && c <= 3);
}

int BFS(vector<int>& res, int r, int c, vector<vector<int>> board)
{
    cout << "\nres: ";
    for(auto r: res)
        cout << r << ' ';
    cout << "\n";
    int ans = 0;
    int sr = r, sc = c;
    for(auto& target: res)
    {
        for(int i=0; i<2; i++)
        {
            queue<pair<int, int>> q;
            vector<vector<int>> dist(4, vector<int>(4, -1));
            q.push({sr, sc});
            dist[sr][sc] = 0;
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                if(board[cur.first][cur.second] == target)
                {
                    board[cur.first][cur.second] = 0;
                    ans += dist[cur.first][cur.second] + 1;
                    sr = cur.first;
                    sc = cur.second;
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
                    int cx = cur.first;
                    int cy = cur.second;
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
                    
                    q.push({cx, cy});
                    dist[cx][cy] = dist[cur.first][cur.second] + 1;
                }
            }
        }
    }
    
    return ans;
}

void DFS(unordered_set<int>& cards, vector<bool> used, vector<int>& res, int& answer, int r, int c, vector<vector<int>>& board)
{
    if(res.size() == cards.size())
    {
        answer = min(answer, BFS(res, r, c, board));
    }
    for(auto& card: cards)
    {
        if(used[card]) continue;
        used[card] = true;
        res.push_back(card);
        DFS(cards, used, res, answer, r, c, board);
        res.pop_back();
        used[card] = false;
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x3f3f3f3f;
    
    unordered_set<int> cards;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j] != 0) cards.insert(board[i][j]);
        }
    }
    
    vector<bool> used(7, false);
    vector<int> res;
    DFS(cards, used, res, answer, r, c, board);
    return answer;
}