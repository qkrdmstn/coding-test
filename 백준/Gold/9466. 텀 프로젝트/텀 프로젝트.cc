#include<iostream>
using namespace std;

int t;
int arr[100001];
int visited[100001]; //-1: matched, 0: not visited

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] != 0)
				continue;

			int cur = i;
			while (true) {
				visited[cur] = i;
				cur = arr[cur];

				if (visited[cur] == i) {
					while (visited[cur] != -1) {
						visited[cur] = -1;
						cur = arr[cur];
					}
					break;
				}
				else if (visited[cur] != 0)
					break;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i] != -1)
				cnt++;
		}
		cout << cnt << "\n";
	}

	//중요!! 방문을 표시할 때 현재 분기점(시작 노드)로 표시하여 순환을 확인
	// 순환이 확인되면 해당 순환을 돌면서 matched 표시를 진행.
	// 이를 모든 노드에 대해서 수행
	// BFS라고 무조건 queue가 사용된다는 고정관념을 버릴 것.
	return 0;
}