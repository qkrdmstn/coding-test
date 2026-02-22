#include <iostream>
#include <vector>
using namespace std;

int n, k;
int weights[105];
int values[105];

void Input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i] >> values[i];
    }
}

int main(void)
{
    Input();
    //dp[i][j]: 물품이 i번째까지 있고, j만큼의 무게 제한일 때 가치의 최댓값.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int wi = weights[i];
            int vi = values[i];

            //현재 물품이 무게 제한을 넘는다면 담지 못한다.
            if (wi > j)
                dp[i][j] = dp[i - 1][j];
            //무게 제한을 넘지 않는다면 물건을 담거나 담지 않는 것 중 최댓값을 선택.
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + vi);
        }
    }
    cout << dp[n][k] << endl;
}