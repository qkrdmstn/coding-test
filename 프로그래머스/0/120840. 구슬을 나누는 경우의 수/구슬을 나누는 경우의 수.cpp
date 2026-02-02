#include <string>
#include <vector>

using namespace std;

long long solution(int balls, int share) {
    long long answer = 0;
    if(balls - share < share) share = balls-share;
    
    //combination
    answer = 1;
    for(int i=1; i<=share; i++)
    {
        answer = (answer * balls) / i;
        balls--;        
    }
    return answer;
}