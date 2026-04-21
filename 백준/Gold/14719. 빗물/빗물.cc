#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int h, w;
	cin >> h >> w;

	vector<int> arr(w,0);
	for(int i=0; i<w; i++)
		cin >> arr[i];
	int ans = 0;
	int leftMax = arr[0];
	int leftIdx = 1;
	int rightMax = arr[w-1];
	int rightIdx = w-2;;
	while(leftIdx <= rightIdx)
	{
		if (leftMax < rightMax)
		{
			if(arr[leftIdx] > leftMax)
				leftMax = arr[leftIdx];
			else
				ans += leftMax - arr[leftIdx];
			leftIdx++;
		}
		else
		{
			if (arr[rightIdx] > rightMax)
				rightMax = arr[rightIdx];
			else
				ans += rightMax - arr[rightIdx];
			rightIdx--;
		}
	}
	cout << ans;
	return 0;
}