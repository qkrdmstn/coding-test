#include<iostream>
#include<string>
using namespace std;

int main()
{
    int p[100][100] = { {0} };
    int n, a, b, cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = a; j < a + 10; j++)
        {
            for (int k = b; k < b + 10; k++)
            {
                p[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (p[i][j] == 1)
                cnt++;
        }
    }

    cout << cnt;
    return 0;
}