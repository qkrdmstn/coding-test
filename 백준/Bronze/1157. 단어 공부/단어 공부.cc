#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    int n[123] = { 0 }, sum[26] = { 0 }, max = 0, index;
    bool c; //가장 많이 사용된 알파벳이 여러 개인 경우

    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        int b = a[i];
        n[b]++;
    }

    for (int i = 0; i < 26; i++)
    {
        sum[i] = n[65 + i] + n[97 + i];
        if (sum[i] >= max)
        {
            if (max == sum[i])
                c = true;
            else
                c = false;

            max = sum[i];
            index = i;
        }
    }

    if (c)
        cout << "?";
    else
        cout << (char)(index + 65);

    return 0;
}