#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> partOfPhoneMap;
    
    for(int i=0; i<phone_book.size(); i++)
    {
        string s = "";
        for(int j=0; j<phone_book[i].length(); j++)
        {
            s += phone_book[i][j];
            partOfPhoneMap[s]++;
        }
    }
    
     for(int i=0; i<phone_book.size(); i++)
     {
         if(partOfPhoneMap[phone_book[i]] >= 2)
             return false;
     }
    return true;
}