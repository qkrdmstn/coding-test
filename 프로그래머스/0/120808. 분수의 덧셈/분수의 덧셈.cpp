#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    //합 계산
    int numer = numer1*denom2 + numer2*denom1;
    int denom = denom1*denom2;
    
    //약분
    for(int i=max(numer, denom); i>=1; i--)
    {
        if(numer % i == 0 && denom % i == 0)
        {
            numer /= i;
            denom /= i;
        }
    }
    answer.push_back(numer);
    answer.push_back(denom);
    return answer;
}