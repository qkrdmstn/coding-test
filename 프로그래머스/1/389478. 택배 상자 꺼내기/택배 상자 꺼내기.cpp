#include <string>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int diff = (w - ((num-1) % w) - 1) * 2 + 1;
    while(num <= n){
        answer++;
        if(answer % 2 == 1)
            num += diff;
        else
            num += 2*w-diff;
    }
    return answer;
}