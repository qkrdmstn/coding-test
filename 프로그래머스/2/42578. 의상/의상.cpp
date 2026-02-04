#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    //각 종류에 대한 옷을 count 합니다.
    unordered_map<string, int> kindOfClothes;
    for(int i=0; i<clothes.size(); i++)
        kindOfClothes[clothes[i][1]]++;
    
    //착용하지 않는 경우까지 포함하여 경우의 수를 구합니다.
    for(auto c: kindOfClothes)
        answer *= c.second + 1;
    
    //한 벌도 착용하지 않는 경우를 제외합니다.
    return answer - 1;
}