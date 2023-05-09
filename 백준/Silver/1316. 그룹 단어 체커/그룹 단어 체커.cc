#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    int n, count = 0;
    bool groupWord[26], check = true;
    cin >> n;
    //97-122 26개 a-z

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            groupWord[j] = false;
        check = true;

        cin >> a;
        for (int j = 0; j < a.length(); j++)
        {
            if (groupWord[a[j] - 97]) //이미 나왔던 알파벳이라면
                check = false;

            groupWord[a[j] - 97] = true; //한 번 나온 알파벳 표시
            while (a[j + 1] == a[j]) //같은 단어 skip
                j++;
        }
       
        if (check)
            count++;
    }
    cout << count;
    return 0;
}