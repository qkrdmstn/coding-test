#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{   
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNumbers;
    for(int i=0; i<numbers.size(); i++)
        stringNumbers.push_back(to_string(numbers[i]));
    
    sort(stringNumbers.begin(), stringNumbers.end(), cmp);
    
    //가장 큰 수가 0이라면 "0"만 출력
    if(stringNumbers[0] == "0") return "0";
    
    for(int i=0; i<numbers.size(); i++)
        answer += stringNumbers[i];
    return answer;
}