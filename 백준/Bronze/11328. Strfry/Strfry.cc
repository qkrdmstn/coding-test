#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        
        int characterCnt[26] = {};
        for(int j=0; j<str1.length(); j++)
            characterCnt[str1[j] - 'a']++;
        for(int j=0; j<str2.length(); j++)
            characterCnt[str2[j] - 'a']--;

        bool isPossible = true;
        for(int j=0; j<26; j++){
            if(characterCnt[j] != 0)
                isPossible = false;
        }
        if(isPossible)
            cout <<"Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}