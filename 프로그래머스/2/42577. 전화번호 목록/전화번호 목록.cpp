#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    //모든 전화번호의 부분 집합을 키 값으로 hash에 count 합니다.
    unordered_map<string, int> prefixCount;
    for(int i=0; i<phone_book.size(); i++)
    {
        string s = "";
        for(int j=0; j<phone_book[i].length(); j++)
        {
            s += phone_book[i][j];
            prefixCount[s]++;
        }
    }
    
    //온전한 문자열을 키값으로 hash 테이블 데이터에 접근합니다.
    //이때, 자기 자신을 포함하므로, count가 2 이상이어야 합니다.
     for(int i=0; i<phone_book.size(); i++)
     {
         if(prefixCount[phone_book[i]] >= 2)
             return false;
     }
    return true;
}