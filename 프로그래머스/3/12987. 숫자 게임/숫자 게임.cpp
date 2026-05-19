#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // 중복 가능한 set 자료구조에 넣어 upper_bound를 사용
    multiset<int> b(B.begin(), B.end());
    for(auto& a: A)
    {
        // a 값보다 큰 수가 있다면 승점 + 1, 그 수 지우기
        auto it = b.upper_bound(a);
        if(it != b.end())
        {
            answer++;
            b.erase(it);
        }
        // 없다면 가장 작은 수 지우기
        else
            b.erase(b.begin());
    }
    
    return answer;
}