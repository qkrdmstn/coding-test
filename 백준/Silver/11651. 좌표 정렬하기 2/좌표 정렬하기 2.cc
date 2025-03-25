#include <iostream>
#include <string>
using namespace std;

int n;
pair<int, int> arr[100001];
pair<int, int> temp[100001];

void Merge(int start, int end)
{
	int mid = (start + end) / 2;

	int idxA = start;
	int idxB = mid;

	for (int i = start; i < end; i++) {
		if (idxA == mid)
			temp[i] = arr[idxB++];
		else if (idxB == end)
			temp[i] = arr[idxA++];
		//y 좌표가 같으면 x 좌표 비교
		else if (arr[idxA].second == arr[idxB].second) {
			if (arr[idxA].first <= arr[idxB].first)
				temp[i] = arr[idxA++];
			else
				temp[i] = arr[idxB++];
		}
		else if (arr[idxA].second < arr[idxB].second)
			temp[i] = arr[idxA++];
		else
			temp[i] = arr[idxB++];
	}
	for (int i = start; i < end; i++)
		arr[i] = temp[i];
}

void MergeSort(int start, int end)
{
	if (start + 1 == end)
		return;

	int mid = (start + end) / 2;
	MergeSort(start, mid);
	MergeSort(mid, end);
	Merge(start, end);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = {x, y};
	}

	MergeSort(0, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
	return 0;
}