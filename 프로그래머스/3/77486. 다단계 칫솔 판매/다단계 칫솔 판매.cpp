#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // 조직 구성원의 이익금과 참여시킨 사람의 정보를 각각 map으로 구성합니다.
    unordered_map<string, string> nxt;
    unordered_map<string, int> money;
    for(int i=0; i<(int)enroll.size(); i++)
    {
        nxt[enroll[i]] = referral[i];
        money[enroll[i]] = 0;
    }
    
    // 이익금의 분배를 시뮬레이션합니다.
    for(int i=0; i<(int)seller.size(); i++)
    {
        int curMoney = amount[i] * 100;
        string cur = seller[i];
        while(true)
        {
            // 자신을 참여시킨 사람에게 이익금의 10%를 나눕니다
            int nxtMoney = curMoney * 0.1;
            money[cur] += curMoney - nxtMoney;
            curMoney = nxtMoney;
            cur = nxt[cur];
            if(curMoney < 1 || cur == "-") break;
        }
    }
    
    // enroll 배열의 순서에 맞게 answer를 구성합니다.
    for(const auto& e: enroll)
        answer.push_back(money[e]);
    
    return answer;
}