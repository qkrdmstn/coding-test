#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // 이익금을 분배할 트리를 구성합니다.
    unordered_map<string, string> parent;
    for(int i=0; i<enroll.size(); i++)
        parent[enroll[i]] = referral[i];
    
    // 각 판매자로부터, 부모를 따라 올라가 이익금을 분배합니다.
    unordered_map<string, int> money;
    for(int i=0; i<seller.size(); i++)
    {
        int curMoney = amount[i] * 100;
        string curName = seller[i];
        while(curMoney >= 1)
        {
            int fee = curMoney/10;
            money[curName] += curMoney - fee;
            curName = parent[curName];
            curMoney = fee;
        }
    }
   
    // enroll에 적힌 순서대로 answer에 수익 저장
    for(int i=0; i<enroll.size(); i++)
        answer.push_back(money[enroll[i]]);
    return answer;
}