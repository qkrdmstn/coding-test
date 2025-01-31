#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    
    int result = a*b*c;
    int cnt[10] = {0,};
    while(result != 0){
        cnt[result%10]++;
        result /=10;
    }

    for(int i=0; i<10; i++)
        cout << cnt[i] << "\n";
    return 0;
}