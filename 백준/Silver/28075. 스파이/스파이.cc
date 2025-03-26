#include <iostream>
using namespace std;

int n, m;
int arr[2][3];
int score, ans;

void func(int day, int place)
{
    if (day == n) {
        if(score >= m)
            ans++;
        return;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == place)
                score += arr[i][j] / 2;
            else
                score += arr[i][j];

            func(day + 1, j);

            if (j == place)
                score -= arr[i][j] / 2;
            else
                score -= arr[i][j];
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    
    func(0, -1);

    cout << ans;
    return 0;
}