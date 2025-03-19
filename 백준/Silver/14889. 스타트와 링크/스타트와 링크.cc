#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 1e9;
int board[22][22];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	//n명 중에 n/2명을 선택하는 조합을 순회 0: 스타트팀, 1: 링크팀
	vector<int> brute(n);
	fill(brute.begin() + n / 2, brute.end(), 1);
	do {
		int start = 0;
		int link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				//스타트 팀
				if (brute[i] == 0 && brute[j] == 0) {
					start += board[i][j] + board[j][i];
				}
				//링크 팀
				else if (brute[i] == 1 && brute[j] == 1) {
					link += board[i][j] + board[j][i];
				}
			}
		}
		ans = min(ans, abs(start - link));
	} while (next_permutation(brute.begin(), brute.end()));
	cout << ans;

	return 0;
}