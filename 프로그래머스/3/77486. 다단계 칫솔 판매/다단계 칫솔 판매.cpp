#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, int> nameToIdx;
    unordered_map<string, string> parent;

    for(int i=0; i<enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
        nameToIdx[enroll[i]] = i;
    }
    
    for(int i=0; i<seller.size(); i++)
    {
        string name = seller[i];
        int money = amount[i] * 100;
        
        while(name != "-" && money > 0)
        {
            int toParent = money / 10;
            int myMoney = money - toParent;
            answer[nameToIdx[name]] += myMoney;
            name = parent[name];
            money = toParent;
            if(money == 0) break;
        }
    }
    return answer;
}