#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    for(int i=-2000; i<=2000; i++)
    {
        int sum = 0;
        for(int j=i; j<i+num; j++)
            sum += j;  
        if(sum == total)
        {
            for(int j=i; j<i+num; j++)
                answer.push_back(j);
            break;
        }
    }
    return answer;
}