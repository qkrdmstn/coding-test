#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool Check(int x, int y, vector<vector<int>>& key, vector<vector<int>>& lock, int m, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int kx = i-x, ky = j-y;
            if(kx >= 0 && kx < m && ky >= 0 && ky < m)
            {
                if(key[kx][ky] == lock[i][j]) return false;
            }
            else if(lock[i][j] == 0) return false;
        }
    }
    
    return true;
}

vector<vector<int>> Rotate(vector<vector<int>>& key, int m)
{
    vector<vector<int>> rotKey(m, vector<int>(m));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            rotKey[j][m-1-i] = key[i][j];
        }
    }
    return rotKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    int n = lock.size();
    int m = key.size();
    for(int x=-(m-1); x<n; x++)
    {
        for(int y=-(m-1); y<n; y++)
        {
            for(int dir=0; dir<4; dir++)
            {
                key = Rotate(key, m);
                if(Check(x, y, key, lock, m, n)) return true;
            }
        }
    }
    return false;
}