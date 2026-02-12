#include <string>
#include <vector>

using namespace std;

int maxCnt = 0;
bool used[10];
void func(int k, vector<vector<int>>& dungeons, int cnt)
{
    maxCnt = max(cnt, maxCnt);
    for(int i=0; i<dungeons.size(); i++)
    {
        if(used[i] || k < dungeons[i][0]) continue;
        used[i] = true;
        func(k-dungeons[i][1], dungeons, cnt + 1);
        used[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    func(k, dungeons, 0);
    return maxCnt;
}