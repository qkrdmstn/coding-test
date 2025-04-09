#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	vector<int> p, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > 0)
			p.push_back(a);
		else
			n.push_back(a);
	}

	//절댓값의 크기를 기준으로 각각 내림차순 정리
	sort(p.begin(), p.end(), greater<>());
	sort(n.begin(), n.end());

	int pSize = p.size();
	for (int i = 0; i < pSize - 1; i += 2) {
		ans += p[i] * p[i + 1];
		if (p[i + 1] == 1)
			ans++;
	}
	//홀수일 경우 마지막 수 더하기
	if (pSize % 2 == 1)
		ans += p[pSize - 1];

	//음수 계산
	int nSize = n.size();
	for (int i = 0; i < nSize - 1; i += 2) {
		ans += n[i] * n[i + 1];
	}
	//홀수일 경우 처리
	if (nSize % 2 == 1)
		ans += n[nSize - 1];

	cout << ans;
	return 0;

	/*
	양수와 (0 + 음수)를 따로 저장한 뒤, 절댓값을 기준으로 내림차순으로 정렬해서
	두 수씩 묶기
	추가로 1에 대한 예외처리 진행
	*/
}