#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    int arr[100001] = {};
    int cnt[1000001] = {};
    
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    cin >> x;

    int result = 0;
    for(int i=1; i<=n; i++){
        cnt[arr[i]]++;

        int idx = x-arr[i];
        if(idx == arr[i])
            continue;
        if(idx > 1000000 || idx < 0)
            continue;
        if(cnt[idx] == 1)
            result++;
    }

    cout << result;
    return 0;
}