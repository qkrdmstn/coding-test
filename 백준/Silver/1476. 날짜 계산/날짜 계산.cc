#include <iostream>
using namespace std;

int e, s, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> s >> m;

    for (int year = 1;; year++) {
        if ((year - e) % 15 == 0 &&
            (year - s) % 28 == 0 &&
            (year - m) % 19 == 0) {
            cout << year;
            break;
        }
    }
    return 0;
}
