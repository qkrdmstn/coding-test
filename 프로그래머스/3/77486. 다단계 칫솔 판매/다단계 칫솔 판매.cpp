#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> parent;
    for(int i=0; i<enroll.size(); i++)
        parent[enroll[i]] = referral[i];
    
    unordered_map<string, int> money;
    for(int i=0; i<seller.size(); i++)
    {
        string cur = seller[i];
        int totalMoney = amount[i] * 100;
        while(cur != "-" && totalMoney >= 1)
        {
            int fee = totalMoney / 10;;
            money[cur] += (totalMoney - fee);
            
            cur = parent[cur];
            totalMoney = fee; 
        }
        money[cur] += totalMoney;
    }
    
    for(auto& e: enroll)
        answer.push_back(money[e]);
    return answer;
}