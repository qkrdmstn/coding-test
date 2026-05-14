#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int q = s/n;
    int r = s%n;
    answer.resize(n, q);
    for(int i = n-r; i<n; i++)
        answer[i]++;
    
    if(q <= 0) return {-1};
    return answer;
}