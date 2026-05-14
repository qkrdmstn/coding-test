#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int n = gems.size();
    int totalKind = unordered_set<string>(gems.begin(), gems.end()).size();
    unordered_map<string, int> count;
    
    int minLen = n + 1;
    int l = 0;
    for(int r=0; r<n; r++)
    {
        count[gems[r]]++;
        while(count.size() == totalKind)
        {

            int len = r-l+1;
            if(len < minLen)
            {
                minLen = len;
                answer = {l+1, r+1};
            }
            count[gems[l]]--;
            if(count[gems[l]] == 0) count.erase(gems[l]);
            l++;
        }
    }
    return answer;
}