#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<vector<int>>& key, vector<vector<int>>& lock, int x, int y)
{
    int m = key.size();
    int n = lock.size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i >= x && i < x + m && j >= y && j < y + m)
            {
                if(lock[i][j] == key[i-x][j-y] ) 
                    return false;
            }
            else
            {
                if(lock[i][j] == 0)
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> Rotate(vector<vector<int>>& key)
{
    int m = key.size();
    vector<vector<int>> newKey(m, vector<int>(m));
    for(int i=0; i<key.size(); i++)
    {
        for(int j=0; j<key.size(); j++)
            newKey[m-1-j][i] = key[i][j];
    }
    return newKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int n = lock.size();
    int m = key.size();
    for(int rot=0; rot<4; rot++)
    {
        for(int i=-m+1; i<n; i++)
        {
            for(int j=-m+1; j<n; j++)
            {
                if(check(key, lock, i, j)) return true;
            }
        }
        key = Rotate(key);
    }
    return false;
}