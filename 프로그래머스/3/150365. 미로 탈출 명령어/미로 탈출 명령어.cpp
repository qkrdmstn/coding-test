#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char dir[4] = {'d','l','r','u'};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int minDist = abs(x-r) + abs(y-c);
    if(k < minDist || (k-minDist) % 2 != 0) return "impossible";
    
    
    while(k>0)
    {
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            int nxtDist = abs(nx-r) + abs(ny-c);
            if(nxtDist <= k-1)
            {
                answer += dir[i];
                x = nx;
                y = ny;
                k--;
                break;
            }
        }
    }
    return answer;
}