#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    if(price >= 500'000) answer = price * 0.8;
    else if(price >= 300'000) answer = price * 0.9;
    else if(price >= 100'000) answer = price * 0.95;
    else answer = price;
    return answer;
}