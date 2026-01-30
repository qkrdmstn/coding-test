#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    num1 *= 1000;
    answer = num1 / num2;
    return answer;
}