#include <iostream>
#include <queue>
using namespace std;

class cmp {
public:
	//a는 부모 노드, b는 자식 노드, true라면 swap을 진행
	bool operator() (int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, cmp> pq;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
	return 0;
}