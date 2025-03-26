#include <iostream>
using namespace std;

int arr[10001];
int n, k;
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> k;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            idx++;
            if (idx == k) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}