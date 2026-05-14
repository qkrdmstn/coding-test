#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    multiset<int> bSet(B.begin(), B.end());
    for(auto& a: A)
    {
        auto it = bSet.upper_bound(a);
        if(it != bSet.end())
        {
            bSet.erase(it);
            answer++;
        }
        else
            bSet.erase(bSet.begin());
    }
    return answer;
}