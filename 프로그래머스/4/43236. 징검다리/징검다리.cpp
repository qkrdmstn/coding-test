#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GetHowManyRemoveRock(int minDist, vector<int>& rocks, int distance)
{ 
    int removeRockCnt = 0;
    int prevRockPos = 0;
    for(int i=0; i<rocks.size(); i++)
    {
        if((rocks[i] - prevRockPos) < minDist)
            removeRockCnt++;
        else
            prevRockPos = rocks[i];
    }
    if(distance - prevRockPos < minDist)
        removeRockCnt++;
    return removeRockCnt;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int st = 1;
    int ed = distance;
    
    while(st <= ed)
    {
        int m = (st + ed) / 2;
        if(GetHowManyRemoveRock(m, rocks, distance) <= n)
        {
            answer = m;
            st = m+1;
        }
        else
            ed = m-1;
    }
    return answer;
}