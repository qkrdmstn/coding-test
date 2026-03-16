#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    if(number == N) return 1;
    unordered_set<int> s[9];
    
    int cur = N;
    for(int i=1; i<=8; i++)
    {
        s[i].insert(cur);
        cur = cur * 10 + N;
    }
    
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<i; j++)
        {
            for(auto &d: s[i-j])
            {
                for(auto &p: s[j])
                {
                    s[i].insert(d+p);
                    s[i].insert(d-p);
                    s[i].insert(d*p);
                    if(p!=0) s[i].insert(d/p);
                }
            }
            if(s[i].count(number) != 0)
                return i;
        }
    }
    return -1;
}