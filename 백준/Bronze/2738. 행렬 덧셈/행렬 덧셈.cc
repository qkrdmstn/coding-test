#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    int A[100][100], B[100][100];
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] + B[i][j];
            if (j != m - 1)
                cout << " ";
        }
        if(i != n-1)
            cout << endl;
    }
    return 0;
}