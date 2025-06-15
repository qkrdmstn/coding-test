#include <iostream>
using namespace std;

int dist[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 10000;
			if (i == n || j == n) dist[i][j] = 100;
			if (i == j) dist[i][j] = 0;
		}
	}

	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

	/*
	문제에서 주어진 코드를 보고 첫 번째 코드, 두 번째 코드의 차이점을 분석해서
	틀린 데이터가 9700개 이상 나오는 인접 행렬을 생성하는 코드를 작성해야 됨.
	이는 dist 배열에 넣음

	풀이:
	지구이가 작성한 틀린 코드(첫 번째 코드)는 인접 행렬 D를 생성
	올바른 코드는 인접행렬 E를 생성
	이때 D의 잘못된 부분은 dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
	수행 과정에서 거쳐가는 노드에 해당하는 mid 범위가 1~n-1까지라는 점이다.
	D와 E가 다른 부분은 dist[st][ed] > dist[st][N] + dist[mid][N]에서 발생한다.
	따라서, 기본 값을 10000으로 설정. n을 거쳐갈 때는 두 개의 값을 더해도 10000을 넘지 못하도록
	100으로 설정하면 데이터가 잘못되게 된다.
	*/
}