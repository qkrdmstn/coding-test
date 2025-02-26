#include<iostream>
#include<queue>
using namespace std;

int n, k;
bool visited[2][500001];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}

	q.push(n);
	visited[0][n] = true;

	int time = 0;
	while (!q.empty()) {
		k += time;
		if (k > 500000) {
			cout << -1;
			return 0;
		}

		if (visited[time % 2][k]) { //현재 홀/짝 시간에 이미 방문했던 곳이면 수진이는 머무를 수 있음.
			cout << time;
			return 0;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cur = q.front();
			q.pop();
			if (cur == k) {
				cout << time;
				return 0;
			}

			for (int next : {cur - 1, cur + 1, 2 * cur}) {
				if (next < 0 || next > 500000)
					continue;
				if (visited[1-(time % 2)][next])
					continue;

				q.push(next);
				visited[1 - (time % 2)][next] = true;
			}
		}
		time++;
	}
	cout << -1;

	/*
	정리.
	1.queue의 size를 이용한 반복문을 사용하면, BFS의 현재의 깊이를 알 수 있음
	2. t초에 수진이의 위치가 x를 (t,x)로 표현하면, (t+1, x-1), (t+2,x)로 2초를 사용하여 제자리에 머무를 수 있다.
	3. 2에 의해 동생이 t초에 방문한 위치가 이미 수진이가 이전에 방문한 위치라면 홀/짝이 일치할 경우 수진이는 그 자리에 머무르는 것으로 동생을 찾을 수 있다.
	ex) 동생이 11초에 13을 방문함. 그러나 이미 수진이가 5초에 13을 방문한 적 있다면, 7, 9, 11초동안 2의 과정을 거쳐 11초에 동생을 찾는다.
	*/

	return 0;
}