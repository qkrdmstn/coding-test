#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0x3f3f3f3f;
    
    multiset<int> s;
    int left = 0;
    for(int right=0; right<(int)stones.size(); right++)
    {
        s.insert(stones[right]);


        if(s.size() > k)
        {
            auto it = s.find(stones[left]);
            if(it != s.end()) s.erase(it);
            left++;
        }
        if(s.size() == k)
        {
            int rangeMax = *s.rbegin();
            answer = min(answer, rangeMax);
        }
    }
    return answer;
}