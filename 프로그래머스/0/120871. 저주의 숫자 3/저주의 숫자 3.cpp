#include <string>
#include <vector>

using namespace std;

bool IsPossible(int n)
{
    if(n%3 == 0) return false;
    while(n)
    {
        if(n%10 == 3) return false;
        n/=10;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    vector<int> array;
    
    int idx = 0;
    while(array.size() <= 100)
    {
        if(IsPossible(idx))
            array.push_back(idx);
        idx++;
    }
    answer = array[n-1];
    return answer;
}