#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int lastAttackTime = attacks[attacks.size() - 1][0];
    int attackIdx = 0;
    int continuous = 0;
    int curHealth = health;
    for(int i=1; i<=lastAttackTime; i++){
        if(i == attacks[attackIdx][0]){
            curHealth -= attacks[attackIdx][1];
            if(curHealth <= 0) break;
            continuous = 0;
            attackIdx++;
        }
        else{
            curHealth = min(curHealth + bandage[1], health);
            continuous++;
            if(continuous == bandage[0]){
                continuous = 0;
                curHealth = min(curHealth + bandage[2], health);
            }
        }
    }
    if(curHealth <= 0) answer = -1;
    else answer = curHealth;
    return answer;
}