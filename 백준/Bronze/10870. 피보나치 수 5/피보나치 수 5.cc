#include <iostream>
using namespace std;

int n;
int fibo(int n)
{
    if (n < 2)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}
int main(void)
{
    cin >> n;
    cout << fibo(n);

    return 0;
}