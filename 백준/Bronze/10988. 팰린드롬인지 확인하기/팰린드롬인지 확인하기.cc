#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    bool b = true;
    cin >> a;

    for (int i = 0; i < (a.length()/2); i++)
    {
        if (a[i] != a[a.length() -1 - i])
            b = false;
    }
    if (b)
        cout << "1";
    else
        cout << "0";

    return 0;
}