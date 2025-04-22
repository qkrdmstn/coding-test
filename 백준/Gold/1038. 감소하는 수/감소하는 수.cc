#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
vector<bool> a(10, 0);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 9; i >= 0; i--) {
		a[i] = 1;
		do {
			if (cnt != n)
				cnt++;
			else {
				for (int j = 0; j < 10; j++) {
					if (a[j]) cout << 9 - j;
				}
				return 0;
			}
		} while (next_permutation(a.begin(), a.end()));
	}
	cout << -1;
	return 0;

	/*
	감소하는 수는 같은 수를 여러번 쓸 수 없음
	-> 0-9까지 n개를 선택해서 n자리의 수를 만들고 내림차순으로 정렬하기.
	ex) next_permutation으로 0-9까지 중 3개를 고름 0010100010
	2, 4, 8 -> 842가 됨
	*/
}