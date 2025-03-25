#include <iostream>
using namespace std;

int n, m;
int pivotA, pivotB;
int arrA[1000000];
int arrB[1000000];
int result[2000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arrA[i];
	for (int j = 0; j < m; j++)
		cin >> arrB[j];

	int idx = 0;
	while (true) {

		if (pivotA < n && pivotB < m) {
			if (arrA[pivotA] < arrB[pivotB])
				result[idx++] = arrA[pivotA++];
			else
				result[idx++] = arrB[pivotB++];
		}
		else if (pivotA < n)
			result[idx++] = arrA[pivotA++];
		else if (pivotB < m)
			result[idx++] = arrB[pivotB++];
		else
			break;
	}

	for (int i = 0; i < idx; i++)
		cout << result[i] << ' ';

	return 0;
}