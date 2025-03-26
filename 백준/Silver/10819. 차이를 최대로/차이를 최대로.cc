#include <iostream>
using namespace std;

int n;
int a[9];
int order[9];
bool isUsed[9];
int result, ans;

int clac()
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(a[order[i]] - a[order[i + 1]]);
    }
    return sum;
}

void func(int cnt)
{
    if (cnt == n) {
        ans = max(ans, clac());
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isUsed[i]) continue;

        isUsed[i] = true;
        order[cnt] = i;
        func(cnt + 1);
        isUsed[i] = false;
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    func(0);

    cout << ans;
    return 0;
}