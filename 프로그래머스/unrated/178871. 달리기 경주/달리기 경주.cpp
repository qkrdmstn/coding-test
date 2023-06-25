#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    map<string, int> m;
    
    for(int i=0; i<players.size(); i++)
    {
        m.insert({players[i], i});
    }
    for(int i=0; i<callings.size(); i++)
    {
        int index = m[callings[i]];
        
        string temp = players[index];
        players[index] = players[index-1];
        players[index-1] = temp;
        
        m.erase(players[index]);
        m.erase(players[index-1]);
        m.insert({players[index-1], index-1});
        m.insert({players[index], index});
    }
    vector<string> answer(players);
    return answer;
}