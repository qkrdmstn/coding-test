#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> res(50, vector<int>(9));
int Simulation(vector<int>& seq)
{
    int curPlayerIdx = 0;
    
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        int out = 0;
        int base[3] = {0,0,0};
        while (out < 3)
        {
            int curPlayer = seq[curPlayerIdx];
            int state = res[i][curPlayer];
            if (state == 0)
                out++;
            else if (state == 1)
            {
                score += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            }
            else if (state == 2)
            {
                score += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            }
            else if (state == 3)
            {
                score += base[2] + base[1] + base[0];
                base[2] = 1;
                base[1] = 0;
                base[0] = 0;
            }
            else if (state == 4)
            {
                score += base[2] + base[1] + base[0] + 1;
                base[2] = 0;
                base[1] = 0;
                base[0] = 0;
            }
            curPlayerIdx = (curPlayerIdx + 1)%9;
        }
    }
    return score;
}

void DFS(vector<bool>& used, vector<int>& seq, int& ans)
{
    if (seq.size() == 9)
    {
        ans = max(ans, Simulation(seq));
        return;
    }

    if (seq.size() == 3)
    {
        seq.push_back(0);
        DFS(used, seq, ans);
        seq.pop_back();
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (used[i]) continue;
        used[i] = true;
        seq.push_back(i);
        DFS(used, seq, ans);
        seq.pop_back();
        used[i] = false;
    }
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> res[i][j];
    }

    vector<bool> used(9, false);
    vector<int> seq;
    int ans = 0;

    used[0] = true;
    DFS(used, seq, ans);
    cout << ans;
    return 0;
}