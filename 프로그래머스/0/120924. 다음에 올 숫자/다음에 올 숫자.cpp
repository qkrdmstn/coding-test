#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
   
    if(common[2] - common[1] == common[1] - common[0]) //등차수열인 경우
        answer = common[common.size()-1] + common[2] - common[1];
    else //등비수열인 경우
        answer = common[common.size()-1] * common[2]/common[1];
    return answer;
}