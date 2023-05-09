#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n, m, begin, mid, end;
    int b[101], save[101];
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        b[i] = i; //바구니 초기화
        save[i] = i;
    }

    for (int i = 0; i < m; i++) //회전
    {
        cin >> begin >> end >> mid;
        int B = begin, M = mid;

        for (int r = 1; r <= n; r++)
            save[r] = b[r];
        
        for (int j = mid; j <= end; j++)
        {

            b[B] = b[M];
            B++;
            M++;
        }

        for (int k = begin; k < mid; k++)
        {
            b[B] = save[k];
            B++;
        }

    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}