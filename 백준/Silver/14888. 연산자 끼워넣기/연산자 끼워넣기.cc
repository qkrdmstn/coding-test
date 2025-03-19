#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int num[11];
int minAns = 1e9;
int maxAns = -1e9;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	
	int start = 0;
	vector<int> brute(n - 1);
	for (int i = 0; i < 4; i++) {
		int op;
		cin >> op;
		fill(brute.begin() + start, brute.begin() + start + op, i);
		start += op;
	}

	do {
		int result = num[0];
		for (int i = 0; i < n - 1; i++) {
			if (brute[i] == 0)
				result += num[i + 1];
			else if(brute[i] == 1)
				result -= num[i + 1];
			else if (brute[i] == 2)
				result *= num[i + 1];
			else if (brute[i] == 3)
				result /= num[i + 1];
		}
		minAns = min(minAns, result);
		maxAns = max(maxAns, result);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << maxAns << '\n';
	cout << minAns << '\n';
	return 0;
}