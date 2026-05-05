#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> setList(9);
    
    setList[0].insert(0);
    int num = 0;
    for(int i=1; i<=8; i++)
    {
        num = (num * 10) + N;
        setList[i].insert(num);
        for(int j=1; j<i; j++)
        {
            for(auto &s1: setList[i-j])
            {
                for(auto &s2: setList[j])
                {
                    setList[i].insert(s1 + s2);
                    setList[i].insert(s1 - s2);
                    setList[i].insert(s1 * s2);
                    if(s2 != 0)
                        setList[i].insert(s1 / s2);
                }
            }
        }
        if(setList[i].find(number) != setList[i].end())
            return i;
    }
    
    return -1;
}