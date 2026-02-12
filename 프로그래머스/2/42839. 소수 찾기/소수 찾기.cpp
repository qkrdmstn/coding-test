#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s; //중복을 없애기 위해 set 자료구조를 사용합니다.
bool used[7]; //사용한 숫자 카드를 표시합니다.

bool IsPrime(int num) //소수 판별 함수입니다.
{
    if(num <= 1) return false;
    for(int i=2; i*i<=num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

void func(string str, string &numbers)
{
    cout <<str << endl;
    //현재 만들어진 조합이 소수인지 판별합니다.
    if(str.length() != 0 && IsPrime(stoi(str))) 
        s.insert(stoi(str));
    //최대 길이에 도달하면 반환합니다.
    if(str.length() == numbers.length())
        return;
    //모든 조합을 생성합니다.
    for(int i=0; i<numbers.length(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        func(str + numbers[i], numbers);
        used[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    func("", numbers);
    answer = s.size();
    return answer;
}