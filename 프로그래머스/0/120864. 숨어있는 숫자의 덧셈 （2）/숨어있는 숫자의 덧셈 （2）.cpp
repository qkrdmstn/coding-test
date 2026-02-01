#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for(int i=0; i<my_string.length(); i++)
    {
        int sum = 0;
        while('0' <= my_string[i] && my_string[i] <= '9')
        {
            sum *= 10;
            sum += my_string[i] - '0';
            i++;
        }
        answer += sum;
    }
    return answer;
}