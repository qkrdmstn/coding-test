#include <iostream>
using namespace std;

int main(void)
{
	int h, w;
	cin >> h >> w;

	int heights[501];
	for (int i = 0; i < w; i++)
		cin >> heights[i];

	int ans = 0;
	int leftIdx = 0;
	int rightIdx = w-1;
	int leftMax = heights[leftIdx];
	int rightMax = heights[rightIdx];
	while (leftIdx < rightIdx)
	{
		if (leftMax < rightMax)
		{
			leftIdx++;
			if(heights[leftIdx] >= leftMax)
				leftMax = heights[leftIdx];
			else
				ans += (leftMax - heights[leftIdx]);
		}
		else
		{
			rightIdx--;
			if (heights[rightIdx] >= rightMax)
				rightMax = heights[rightIdx];
			else
				ans += (rightMax - heights[rightIdx]);
		}
	}

	cout << ans;
}