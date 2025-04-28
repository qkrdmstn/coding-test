#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[2005];

//num을 찾으면 index 반환, 못 찾으면 -1 반환
int find(int num, int i, int j)
{
    int s = 0;
    int e = n;
    while (s <= e) {
        int m = (s + e) / 2;
        if (a[m] == num && i != m && j != m)
            return m;
        else if (a[m] == num && a[m + 1] != num && a[m - 1] != num)
            return -1;
        else if (a[m + 1] == num)
            return m + 1;
        else if (a[m] < num)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int result = lower_bound(a, a + n, a[i] - a[j]) - a;
            while (result == i || result == j)
                result++;
            //cout << "i, j, res: " << i << ' ' << j << ' ' << result << '\n';
            if (result < n && a[result] == a[i] - a[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}