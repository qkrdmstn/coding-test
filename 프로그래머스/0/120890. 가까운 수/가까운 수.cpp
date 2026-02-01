#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    for(int i=1; i<array.size(); i++)
    {
        if(abs(n - array[i]) < abs(n - answer))
            answer = array[i];
        else if(abs(n - array[i]) == abs(n - answer) && array[i] < answer)
            answer = array[i];
    }
    return answer;
}