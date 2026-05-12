#include <string>
#include <vector>
#include <iostream>
using namespace std;


void Rotate(vector<vector<int>>& key, int m)
{
    vector<vector<int>> rotKey(m, vector<int>(m));
    for(int r=0; r<m; r++)
    {
        for(int c=0; c<m; c++)
            rotKey[c][m-r-1] = key[r][c];
    }
    key = rotKey;
}

bool IsCorrect(int sr, int sc, vector<vector<int>>& key, vector<vector<int>>& lock, int m, int n)
{
//     cout << "lock: -----------------------------------\n";
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//             cout << lock[i][j] << " ";
//         cout << "\n";
//     }
//     cout << "key:" << sr << " " << sc << " -----------------------------------\n";
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i >= sr && i < sr + m && j >= sc && j < sc + m)
//                 cout << key[i-sr][j-sc] << " ";

//         }
//     }
//     cout << "ed: -----------------------------------\n\n";
    
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i >= sr && i < sr + m && j >= sc && j < sc + m)
            {
                int lockNum = lock[i][j];
                int keyNum = key[i-sr][j-sc];
                if(lockNum == 0 && keyNum == 0) return false;
                else if(lockNum == 1 && keyNum == 1) return false;
            }
            else if(lock[i][j] == 0) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int m = key.size();
    int n = lock.size();
    for(int rot = 0; rot < 4; rot++)
    {
        Rotate(key, m);
        for(int sr = -(m-1); sr < n; sr++)
        {
            for(int sc = -(m-1); sc < n; sc++)
            {
                if(IsCorrect(sr, sc, key, lock, m, n)) return true;
            }
        }           
    }

    return answer;
}