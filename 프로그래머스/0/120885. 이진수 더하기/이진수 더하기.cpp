#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    //두 이진수의 길이를 맞춥니다.
    if(bin1.length() > bin2.length())
    {
        while(bin1.length() != bin2.length())
            bin2 = "0" + bin2;
    }
    else if(bin1.length() < bin2.length())
    {
        while(bin1.length() != bin2.length())
            bin1 = "0" + bin1;
    }
    
    bool carry = false;
    for(int i=bin1.length()-1; i>=0; i--)
    {
        if(bin1[i] == '0' && bin2[i] == '0')
        {
            if(carry)
            {
                answer = "1" + answer;
                carry = false;
            } 
            else 
                answer = "0" + answer;
        }
        else if(bin1[i] == '1' && bin2[i] == '1')
        {
            if(carry) answer = "1" + answer;
            else answer = "0" + answer;
            carry = true;
        }
        else
        {
            if(carry)
                answer = "0" + answer;
            else answer = "1" + answer;
        }
    }
    if(carry) answer = "1" + answer;
    return answer;
}