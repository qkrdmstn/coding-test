#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int t, n, m;
ll sumA[1005], sumB[1005];
vector<ll> a, b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sumA[i] = sumA[i-1] + num;
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        sumB[i] = sumB[i-1] + num;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            a.push_back(sumA[i] - sumA[j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            b.push_back(sumB[i] - sumB[j]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ll target = t - a[i];
        ans += upper_bound(b.begin(), b.end(), target) - lower_bound(b.begin(), b.end(), target);
    }
    cout << ans;
    return 0;

    /*
    누적합 연산을 통해 각 배열에 대한 부배열의 합의 집합을 벡터에 저장
    각 벡터에서 하나씩 뽑아 t가 되는 경우를 이분탐색으로 탐색
    -> 그러나, 같은 숫자가 여러 개인 경우를 생각해 upper - lower를 수행
    */
}