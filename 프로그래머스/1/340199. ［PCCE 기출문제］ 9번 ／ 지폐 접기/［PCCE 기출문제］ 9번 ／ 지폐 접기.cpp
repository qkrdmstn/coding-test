#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wMax = max(wallet[0], wallet[1]);
    int wMin = min(wallet[0], wallet[1]);
    int bMax = max(bill[0], bill[1]);
    int bMin = min(bill[0], bill[1]);
    
    while(bMax > wMax || bMin > wMin){
        bMax /= 2;
        answer++;
        if(bMax < bMin) swap(bMax, bMin);
    }
    return answer;
}