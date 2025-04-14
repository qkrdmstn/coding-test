#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n, c, m, ans;
int truck[2005];
tuple<int, int, int> info[10005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) {
		int f, t, b;
		cin >> f >> t >> b;
		info[i] = { t, f, b };
	}

	sort(info, info + m);

	for (int i = 0; i < m; i++) {
		int f, t, b;
		tie(t, f, b) = info[i];

		bool flag = true;
		for (int j = f; j < t; j++) {
			b = min(b, c - truck[j]);
			if (!b) {
				flag = false;
				break;
			}
		}

		if (flag) {
			ans += b;
			for(int j=f; j<t; j++)
				truck[j] += b;
		}
	}
	cout << ans;

	/*
	가장 빨리 내릴 수 있는 택배부터 가져가도록, 도착지를 기준으로 오름차순 정렬
	truck 배열에 현재 마을에서 트럭에 있는 박스의 개수를 저장하고,
	각 배송정보를 순회하면서 실을 수 있는 박스의 개수를 min으로 측정
	실을 수 있는 박스가 있다면 ans에 더하고 truck capacity에도 추가
	*/
	return 0;
}