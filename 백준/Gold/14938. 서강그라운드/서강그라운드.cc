#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, r;
int item[105];
int dist[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		item[i] = num;
	}

	//거리 INF 초기화
	for (int i = 1; i <= n; i++)
		fill(dist[i], dist[i] + n + 1, INF);

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}

	//플로이드 알고리즘으로 모든 지역 쌍에 대해 거리 계산
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) 
				dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
		}
	}

	//각 지역에서 출발할 경우, 수색범위 내에 있는 지역의 아이템을 sum, 최댓값 저장
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m)
				sum += item[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}