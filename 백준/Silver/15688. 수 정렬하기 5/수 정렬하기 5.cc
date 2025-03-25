#include <iostream>
using namespace std;

int n;
int arr[2000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num;
		arr[num + 1000000]++;;
	}

	for (int i = 0; i < 2000001; i++) {
		while (arr[i]) {
			cout << i- 1000000 << '\n';
			arr[i]--;
		}
	}
	return 0;
}