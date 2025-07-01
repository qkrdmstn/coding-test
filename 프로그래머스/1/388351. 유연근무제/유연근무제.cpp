#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = timelogs.size();
    
    for(int i=0; i<timelogs.size(); i++){
        int timeLimit = schedules[i] + 10;
        if(timeLimit % 100 > 59) timeLimit += 40;
        for(int j=0; j<7; j++){
            int curDay = startday + j;
            if(curDay > 7) curDay = curDay % 8 + 1;
            if(curDay == 6 || curDay == 7) continue;
            if(timelogs[i][j] > timeLimit){
                answer--;
                break;
            }
        }
    }
    return answer;
}