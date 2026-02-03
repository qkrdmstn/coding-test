#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0; i<babbling.size(); i++)
    {
        bool flag = true;
        for(int j=0; j<babbling[i].length(); j++)
        {
            string s = "";
            if(babbling[i][j] == 'a')
                s = "aya";
            else if(babbling[i][j] == 'y')
                s = "ye";
            else if(babbling[i][j] == 'w')
                s = "woo";
            else if(babbling[i][j] == 'm')
                s = "ma";
            
            if(s == "")
            {
                flag = false;
                break;
            }
            for(int k=0; k<s.length(); k++)
            {
                cout << i << ' '<< j << ' ' << k << endl;
                if(babbling[i][j] != s[k] || j >= babbling[i].length())
                {
                    flag = false;
                    break;
                }
                j++;
            }
            j--;
            if(!flag) break;
        }
        if(flag)
        {
            cout << "---------Clear!\n";
            answer ++;
        }
    }
    return answer;
}