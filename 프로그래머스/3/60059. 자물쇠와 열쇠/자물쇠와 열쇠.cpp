#include <string>
#include <vector>

using namespace std;

// 열쇠를 시계방향으로 회전합니다.
vector<vector<int>> Rotate(vector<vector<int>>& key, int m)
{
    vector<vector<int>> newKey(m, vector<int>(m));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
            newKey[j][m-i-1] = key[i][j];
    }
    return newKey;
}

bool IsMatched(int sx, int sy, const vector<vector<int>>& key, const vector<vector<int>>& lock, int n , int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 열쇠 기준 좌표로 변환합니다.
            int x = i-sx;
            int y = j-sy;
            
            // 열쇠와 겹친 부분
            if(x >= 0 && x < m && y >= 0 && y < m)
            {
                // 홈이 채워지지 않거나 돌기가 만난 경우 매칭X
                if(key[x][y] == lock[i][j]) return false;
            }
            // 열쇠와 겹치지 않은 부분에 홈이 있다면 매칭 X
            else if(lock[i][j] == 0) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    
    // 열쇠를 이동 및 회전하면서 자물쇠와의 매칭을 확인합니다.
    // 열쇠와 자물쇠는 한 칸만 겹쳐도 되기 때문에 열쇠는 -m+1 ~ n-1까지 이동할 수 있습니다.
    for(int i=-m+1; i<n; i++)
    {
        for(int j= -m+1; j<n; j++)
        {
            for(int rot=0; rot<4; rot++)
            {
                if(IsMatched(i, j, key, lock, n, m)) 
                    return true;
                key = Rotate(key, m);
            }
        }
    }
    return false;
}