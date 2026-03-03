#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	//d[i]: arr[i]번째 수를 포함하는 증가하는 가장 긴 부분 수열의 {길이, 수열의 마지막 원소}
	vector<int> arr(n);
	vector<int> d(n, 1);
	vector<int> rarr(n);
	vector<int> rd(n, 1);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = rarr[n-1-i] = a;
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//j번쨰 원소가 나보다 작다면, d[i] = maxd[j] + 1
			if (arr[j] < arr[i])
				d[i] = max(d[i], d[j] + 1);
			if (rarr[j] < rarr[i])
				rd[i] = max(rd[i], rd[j] + 1);
		}
	}

	//rd[i]: i번째 원소를 포함하고, i~n-1번째까지 감소하는 가장 긴 부분 수열로 변환
	reverse(rd.begin(), rd.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i] + rd[i] - 1);
	//ans: d[i](0~i번쨰까지 증가하는 가장 긴 부분수열의 길이) 
	// + rd[i](i~n-1번째까지 감소하는 가장 긴 부분수열의 길이)
	// -1(i번째가 중복 원소이기 때문에 뺸다). 
	cout << ans;
	return 0;
}