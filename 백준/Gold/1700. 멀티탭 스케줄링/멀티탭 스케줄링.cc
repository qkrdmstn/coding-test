#include <iostream>
#include <vector>
using namespace std;

const int INF = 200;
int main(void)
{
	int n, k;
	cin >> n >> k;
	
	vector<int> tap(n, -1);
	vector<int> arr;
	vector<int> used(101, false);
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int machine = arr[i];
		if(used[machine]) continue;

		for (int j = 0; j < n; j++)
		{
			if (tap[j] == -1)
			{
				tap[j] = machine;
				used[machine] = true;
				break;
			}
		}

		int maxTime = -1;
		int targetIdx = -1;
		if (!used[machine])
		{
			for (int j = 0; j < n; j++)
			{
				int nxtUseTime = INF;
				for (int l = i + 1; l < k; l++)
				{
					if (arr[l] == tap[j])
					{
						nxtUseTime = l;
						break;
					}
				}

				if (nxtUseTime > maxTime)
				{
					maxTime = nxtUseTime;
					targetIdx = j;
				}
			}

			used[tap[targetIdx]] = false;
			tap[targetIdx] = machine;
			used[machine] = true;
			ans++;
		}
	}

	cout << ans;
	return 0;
}