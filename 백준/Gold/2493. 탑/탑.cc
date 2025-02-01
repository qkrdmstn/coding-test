#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<pair<int, int>> v;

	cin >> n;
	v.push({ 100000001, 0 });
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;

		while (v.top().first < h)
			v.pop();
		cout << v.top().second << " ";
		v.push({ h,i });
	}
	return 0;

	//1. 자신보다 높이가 낮은 탑은 가려지므로, pop 해도 된다는 점
	//2. stack에 pair 형태로 높이와 순번을 같이 저장한다는 점
	//3. 처음에 가장 높은 탑을 세워서 empty 체크를 안해도 된다는 점
}