#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<bool> state(1000001, true);

void PrimeList(int n)
{
    state[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    PrimeList(n);
    for (int i = m; i <= n; i++) {
        if (state[i]) cout << i << '\n';
    }

    return 0;
}