#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> m;
    unordered_set<string> s;
    for(int i=0; i<clothes.size(); i++)
    {
        m[clothes[i][1]]++;
        s.insert(clothes[i][1]);
    }
    
    for(auto &k: s)
        answer *= (m[k] + 1);
    return answer - 1;
}