#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, k;
int dist[25][25];
bool edge[25][25];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	}

	//계산된 최소 시간이 다른 도시를 거쳐 가는 최소 시간과 동일하면 
	//최소 개수를 만족하는 도로가 아님
	for (int st = 0; st < n; st++) {
		for (int ed = st+1; ed < n; ed++) {
			bool isEdge = true;
			for (int mid = 0; mid < n; mid++) {
				if (st == ed || mid == st || mid == ed) continue;

				//주어진 시간이 최소 시간이 아닐 경우
				if (dist[st][ed] > dist[st][mid] + dist[mid][ed]) {
					cout << -1;
					return 0;
				}
				else if (dist[st][ed] == dist[st][mid] + dist[mid][ed]) {
					isEdge = false;
					break;
				}
			}
			if (isEdge)
				edge[st][ed] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (edge[i][j])
				ans += dist[i][j];
		}
	}
	cout << ans;
	return 0;
	/*
	계산된 최소 시간이 다른 도시를 거쳐 가는 최소 시간과 동일하면
	최소 개수를 만족하는 도로에서 제외
	또, 문제의 표현이 애매함 불가능한 경우는 주어진 입력이 최소 시간이 아닐 경우를 뜻함.
	*/
}