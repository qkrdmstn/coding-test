#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    int count = 0;
    cin >> a;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'c')
        {
            if (a[i + 1] == '=' || a[i + 1] == '-')
            {
                count++;
                i++;
            }
            else
                count++;
        }
        else if (a[i] == 'd')
        {
            if (a[i + 1] == 'z' && a[i + 2] == '=')
            {
                count++;
                i += 2;
            }
            else if (a[i + 1] == '-')
            {
                count++;
                i++;
            }
            else
                count++;
        }
        else if (a[i] == 'l')
        {
            if (a[i + 1] == 'j')
            {
                count++;
                i++;
            }
            else
                count++;
        }
        else if (a[i] == 'n')
        {
            if (a[i + 1] == 'j')
            {
                count++;
                i++;
            }
            else
                count++;
        }
        else if (a[i] == 's' || a[i] == 'z')
        {
            if (a[i + 1] == '=')
            {
                count++;
                i++;
            }
            else
                count++;
        }
        else
            count++;
    }
    cout << count;
    return 0;
}