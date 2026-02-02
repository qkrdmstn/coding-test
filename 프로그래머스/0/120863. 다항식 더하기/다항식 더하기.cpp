#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string polynomial) {
    string answer = "";
    stringstream ss(polynomial);
    string str;
    
    int c = 0;
    int xCoef = 0;

    while(ss >> str)
    {
        if(str == "+") continue;
        
        string numString = "";
        if(str[str.length() - 1] == 'x')
        {
            if(str.length() == 1) xCoef++;
            else
            {
                for(int i=0; i<str.length()-1; i++)
                    numString += str[i];
                xCoef += stoi(numString);
            }
        }
        else
            c += stoi(str);
        cout << xCoef << ' ' << c << endl;
    }

    if(xCoef > 1) answer += to_string(xCoef); 
    if(xCoef > 0) answer += "x";
    if(xCoef > 0 && c > 0) answer += " + ";
    if(c > 0) answer += to_string(c);
    return answer;
}