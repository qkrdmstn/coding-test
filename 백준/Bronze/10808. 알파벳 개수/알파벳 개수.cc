#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt[26] ={0,};
    for(int i=0; i<s.length(); i++)
    {
        cnt[s[i]-'a']++;
    }

    for(int i=0; i<26; i++)
        cout << cnt[i] << " ";
    return 0;
}