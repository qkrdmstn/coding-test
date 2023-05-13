#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    int A[9][9], row, col, max = -1;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> A[i][j];
            if (A[i][j] > max)
            {
                row = i + 1;
                col = j + 1;
                max = A[i][j];
            }
        }
    }

    cout << max << endl;
    cout << row << " " << col;
    return 0;
}