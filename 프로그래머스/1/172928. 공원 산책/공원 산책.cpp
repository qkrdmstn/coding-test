#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int h = park.size();
    int w = park[0].size();
    int posX = 0;
    int posY = 0;
    
    //시작 위치 찾기
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(park[i][j] == 'S'){
                posX = i;
                posY = j;
                break;
            }
        }
    }
    
    //EWSN 순서
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for(int i=0; i<routes.size(); i++){
        int idx = 0;
        if(routes[i][0] == 'E')
            idx = 0;
        else if(routes[i][0] == 'W')
            idx = 1;
        else if(routes[i][0] == 'S')
            idx = 2;
        else if(routes[i][0] == 'N')
            idx = 3;
        
        //이동 거리만큼 반복
        int n = (routes[i][2] - '0');
        bool isPass = true;
        for(int j=1; j<=n; j++){
            int nx = posX + dx[idx] * j;
            int ny = posY + dy[idx] * j;
            if(nx >= h || nx < 0 || ny >= w || ny < 0 || park[nx][ny] == 'X'){
                isPass =  false;
                break;
            }
        }
        if(isPass){
            posX += dx[idx] * n;
            posY += dy[idx] * n;
        }
    }
    
    answer.push_back(posX);
    answer.push_back(posY);
    return answer;
}