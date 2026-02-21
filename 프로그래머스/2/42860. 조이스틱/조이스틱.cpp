#include <string>
#include <vector>
#include <iostream>
using namespace std;

int MakeCharacter(char c)
{
    int result = 0;
    if(c < 'N') result = c - 'A';
    else result = 'Z' - c + 1;
    return result;
}

int solution(string name) {
    int answer = name.length() - 1;
    
    int n = name.length();
    int characterMove = 0;
    int cursorMove = n-1;
    for(int i=0; i<n; i++)
        characterMove += MakeCharacter(name[i]);
    for(int i=0; i<n; i++)
    {
        int nxt = i+1;
        while(nxt < n && name[nxt] == 'A')
            nxt++;
        cursorMove = min(cursorMove, i + n - nxt + min(i, n-nxt));
    }
    
    return characterMove + cursorMove;
}