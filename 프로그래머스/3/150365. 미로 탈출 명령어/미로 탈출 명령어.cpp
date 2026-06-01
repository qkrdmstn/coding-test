#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 이동 방향을 알파벳 순서대로 지정합니다.
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
int dir[4] = {'d', 'l', 'r', 'u'};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int minDist = abs(x-r) + abs(y-c);
    // 이동 거리 k가 최단 거리보다 작거나 k-minDist가 홀수라면 목적지에 도달 불가능합니다.
    if(k < minDist || (k-minDist) % 2 != 0) return "impossible";
    
    while(k>0)
    {
        // 알파벳 순서대로 현재 위치에서의 이동 방향을 지정합니다.
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            // 다음 위치에서의 거리가 k-1보다 크면 도달 불가능합니다.
            int nxtDist = abs(nx-r) + abs(ny-c);
            if(nxtDist > k-1) continue;
            answer += dir[i];
            x = nx;
            y = ny;
            k--;
            break;
        }
    }
    
    return answer;
}