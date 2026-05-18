#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

int BFS(vector<int>& res, int r, int c, vector<vector<int>> board)
{
    int result = 0;
    int sr = r, sc = c;
    
    for(int& target: res)
    {
        // target의 쌍을 찾습니다.
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
                    // 커서 이동 횟수 + Enter 입력
                    result += dist[cur.first][cur.second] + 1;
                    board[cur.first][cur.second] = 0;
                    sr = cur.first, sc = cur.second;
                    break;
                }
                // 방향키 커서 이동
                for(int dir=0; dir<4; dir++)
                {
                    int nr = cur.first + dr[dir];
                    int nc = cur.second + dc[dir];
                    if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
                    if(dist[nr][nc] >= 0) continue;
                    q.push({nr, nc});
                    dist[nr][nc] = dist[cur.first][cur.second] + 1;
                }
                
                // ctrl + 방향키 커서 이동
                for(int dir=0; dir<4; dir++)
                {
                    int cr = cur.first, cc = cur.second;
                    int nr = cr + dr[dir], nc = cc + dc[dir];
                    
                    while((nr >= 0 && nr < 4 && nc >= 0 && nc < 4))
                    {
                        cr = nr, cc = nc;
                        if(board[cr][cc] != 0) break;
                        nr += dr[dir];
                        nc += dc[dir];
                    }
                    if(dist[cr][cc] >= 0) continue;
                    q.push({cr, cc});
                    dist[cr][cc] = dist[cur.first][cur.second] + 1;
                }
            }
        }
    }
    return result;
}

// DFS를 통해 카드를 찾는 모든 순서열을 알아냅니다.
void DFS(vector<bool>& used, unordered_set<int>& cards, vector<int>& res, int& ans, int r, int c, vector<vector<int>>& board)
{
    if(res.size() == cards.size())
    {
        // BFS를 통해 지정된 순서열로 카드를 찾습니다.
        ans = min(ans, BFS(res, r, c, board));
        return;
    }
    for(auto& card: cards)
    {
        if(used[card]) continue;
        used[card] = true;
        res.push_back(card);
        DFS(used, cards, res, ans, r, c, board);
        res.pop_back();
        used[card] = false;
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x3f3f3f3f;
    
    // 카드 종류를 중복 없이 저장합니다.
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
    DFS(used, cards, res, answer, r, c, board);
    return answer;
}