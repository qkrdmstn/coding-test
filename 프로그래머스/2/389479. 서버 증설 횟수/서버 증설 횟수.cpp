#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    //각 시간대에 유지되는 서버 갯수 기록
    int curServer[24] = {0,};
    
    for(int i=0; i<players.size(); i++){
        //현재 시간대에 요구되는 서버의 개수를 계산
        int curPlayers = players[i];
        int reqServer = curPlayers/m;
        
        //현재 유지된 서버가 요구 서버보다 적다면 증설
        if(curServer[i] < reqServer){
            int addServer = reqServer - curServer[i];
            answer += addServer;
            //증설된 서버는 현재 시각 + k까지 유지
            for(int j=i; j<i+k; j++){
                if(j > 23) continue;
                curServer[j]+= addServer;
            }
        }
    }
    return answer;
}