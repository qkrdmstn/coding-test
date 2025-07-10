#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll start = 1;
    ll digit = 1;

    /*
    1-9는 9개 -> 9개 * 1자리 = 9
    10-99는 90개 => 180자리
    100-999는 900개 => 2700자리
    */

    //k번째 수가 어느 범위에 있는지 확인
    while (true) {
        ll numbers = 9 * start;
        ll totalDigit = numbers * digit;
        if (k <= totalDigit) break;
        k -= totalDigit;
        start *= 10;
        digit++;
    }

    //k번째 자리에 있는 수를 변환
    ll num = start + (k - 1) / digit;
    if (num > n) {
        cout << -1;
        return 0;
    }

    //num을 string으로 바꿔 앞에서 k번째 수 찾기
    string s = to_string(num);
    cout << s[(k - 1) % digit];

    return 0;
}
