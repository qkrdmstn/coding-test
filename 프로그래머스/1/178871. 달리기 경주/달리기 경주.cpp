#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> m;
    
    for(int i=0; i<players.size(); i++){
        m.insert({players[i], i});
    }
    
    for(int i=0; i<callings.size(); i++){
        string callingPlayer = callings[i];
        int callingNum = m[callingPlayer];
        int beforePlayerNum = callingNum-1;
        string beforePlayer = players[beforePlayerNum];
        
        int tmpInt = m[beforePlayer];
        m[beforePlayer] = callingNum;
        m[callingPlayer] = tmpInt;
        
        string tmpStr = players[beforePlayerNum];
        players[beforePlayerNum] = callingPlayer;
        players[callingNum] = tmpStr;
    }
    return players;
}