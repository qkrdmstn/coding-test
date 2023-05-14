#include<iostream>
using namespace std;

int main()
{
    double n, i = 2, s = 1;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    n--;
    double n6 = n / 6;
   
    while (1)
    {
        if (n6 <= s)
            break;
        s += i;
        i++;
    }

    cout << i;
    return 0;
}