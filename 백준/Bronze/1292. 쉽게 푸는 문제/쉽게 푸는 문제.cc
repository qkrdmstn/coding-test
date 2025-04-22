#include <iostream>
using namespace std;

int a, b;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	int cnt = 0;
	int i = 1;
	int ans = 0;
	while(true){
		for (int j = 0; j < i; j++) {
			cnt++;
			if (cnt >= a && cnt <= b)
				ans += i;
		}
		if (cnt >= b)
			break;
		i++;
	}
	cout << ans;
	return 0;
}