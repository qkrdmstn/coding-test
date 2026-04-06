#include <iostream>
#include <vector>
using namespace std;

int main(void)
{

	int h, w;
	cin >> h >> w;

	vector<int> arr(w);
	for (int i = 0; i < w; i++)
		cin >> arr[i];


	int ans = 0;
	for (int i = 0; i < w; i++)
	{
		int maxL = i;
		int maxR = i;
		for (int l = i - 1; l >= 0; l--)
		{
			if (arr[l] > arr[maxL])
				maxL = l;
		}

		for (int r = i + 1; r < w; r++)
		{
			if (arr[r] > arr[maxR])
				maxR = r;
		}

		if(maxL == i  || maxR == i) continue;
		ans += min(arr[maxL], arr[maxR]) - arr[i];
	}
	cout << ans;
	return 0;
}