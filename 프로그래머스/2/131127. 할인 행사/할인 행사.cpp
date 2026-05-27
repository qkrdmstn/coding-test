#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> m;
    for(int i=0; i<want.size(); i++)
        m[want[i]] = number[i];
    
    int st = 0;
    int n = discount.size();
    for(int ed=0; ed<n; ed++)
    {
        if(ed >= 10)
        {
            m[discount[st]]++;
            st++;
        }
        m[discount[ed]]--;
        
        bool flag = true;
        for(const auto& mm: m)
        {
            if(mm.second != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}