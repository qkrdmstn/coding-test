#include <iostream>
using namespace std;

int n;
int arr[10001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (arr[i] > 0) {
			cout << i << '\n';
			arr[i]--;
		}
	}
	return 0;
}