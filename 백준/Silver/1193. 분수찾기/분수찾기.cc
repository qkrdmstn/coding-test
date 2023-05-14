#include<iostream>
using namespace std;

int main()
{
    int x, s = 1, i = 1;
    cin >> x;
    while (1)
    {
        if (x <= s)
            break;
        i++;
        s += i;
    }
    
    int sequence = x - (s - i);
    int invSequence = i - (x - (s - i)) + 1;
    
    if (i % 2 != 0)
        cout << invSequence << "/" << sequence;
    else
        cout << sequence << "/" << invSequence;

    return 0;
}