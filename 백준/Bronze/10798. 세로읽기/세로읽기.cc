#include<iostream>
#include<string>
using namespace std;

int main()
{
    string A[5];
    bool end[5];

    for (int i = 0; i < 5; i++)
    {
        end[i] = false;
        cin >> A[i];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (end[j])
                continue;
            else if (A[j][i] == '\0')
            {
                end[j] = true;
                continue;
            }
                
            cout << A[j][i];
        }
    }
    return 0;
}