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
	int st = 0;
	int ed = w-1;
	while(st < ed)
	{
		if (arr[st] < arr[ed])
		{
			int l = arr[st];
			while (st < ed && arr[st] <= l)
			{
				ans += l-arr[st];
				st++;
			}

		}
		else
		{
			int r = arr[ed];
			while (st < ed && arr[ed] <= r)
			{
				ans += r - arr[ed];
				ed--;
			}
		}
	}
	cout << ans;
	return 0;
}