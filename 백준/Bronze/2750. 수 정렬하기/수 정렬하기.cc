#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    
    sort(num, num + n);
    
    for(int i=0; i<n; i++){
        cout << num[i] << '\n';
    }
    return 0;
}