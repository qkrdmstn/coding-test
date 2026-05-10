#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    
    vector<unordered_set<int>> s(9);
    int curNum = 0;
    for(int i=1; i<=8; i++)
    {
        curNum = curNum * 10 + N;
        s[i].insert(curNum);
        for(int j=1; j<i; j++)
        {
            int idx1 = j;
            int idx2 = i-j;
            for(auto& s1: s[idx1])
            {
                for(auto& s2: s[idx2])
                {
                    s[i].insert(s1 + s2);
                    s[i].insert(s1 - s2);
                    s[i].insert(s1 * s2);
                    if(s2 != 0)
                        s[i].insert(s1 / s2);
                }
            }
        }
        if(s[i].find(number) != s[i].end())
            return i;
    }
    return -1;
}