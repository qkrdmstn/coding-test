#include <iostream>
using namespace std;

int n, m;
long long ans;
long long a[1005];

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++) {
		int minIdx = 0;
		for (int j = 1; j < n; j++) {
			if (a[j] < a[minIdx])
				minIdx = j;
		}
		swap(a[0], a[minIdx]);

		minIdx = 1;
		for (int j = 1; j < n; j++) {
			if (a[j] < a[minIdx])
				minIdx = j;
		}
		swap(a[1], a[minIdx]);

		long long sum = a[0] + a[1];
		a[0] = a[1] = sum;
	}

	for (int i = 0; i < n; i++)
		ans += a[i];

	cout << ans;
	return 0;
}