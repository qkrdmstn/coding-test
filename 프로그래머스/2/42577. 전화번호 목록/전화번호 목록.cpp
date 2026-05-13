#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), greater<string>());
    
    unordered_set<string> s;
    for(auto& phone: phone_book)
    {
        if(s.find(phone) != s.end()) return false;
        string num = "";
        for(int i=0; i<phone.length(); i++)
        {
            num += phone[i];
            s.insert(num);
        }
    }
       
    return true;
}