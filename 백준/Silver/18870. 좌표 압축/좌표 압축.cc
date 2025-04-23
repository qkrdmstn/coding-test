#include <iostream>
#include <algorithm>
using namespace std;

int n;
int distinctArrLen = 0;
int a[1000005];
int sortedArr[1000005];
int distinctArr[1000005];

int find(int target)
{
	int start = 0;
	int end = distinctArrLen;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (distinctArr[mid] == target)
			return mid;
		else if (target < distinctArr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sortedArr[i] = a[i];
	}

	//정렬 및 중복 제거
	sort(sortedArr, sortedArr + n);
	
	distinctArr[distinctArrLen] = sortedArr[distinctArrLen];
	distinctArrLen++;
	for (int i= 1; i < n; i++) {
		if (sortedArr[i - 1] == sortedArr[i]) continue;
		distinctArr[distinctArrLen] = sortedArr[i];
		distinctArrLen++;
	}

	for (int i = 0; i < n; i++) {
		cout << find(a[i]) << ' ';
	}

	return 0;
}