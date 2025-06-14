#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, r, m, k, cityCnt;
unordered_map<string, int> city_to_id;
vector<int> vis;
int distA[105][105]; //내일로 사용 X
int distB[105][105]; //내일로 사용 O

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r;
	//0-index
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		auto it = city_to_id.find(name);
		if(it == city_to_id.end())
			city_to_id.insert({ name, cityCnt++ });
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		vis.push_back(city_to_id[name]);
	}

	cin >> k;
	for (int i = 0; i < cityCnt; i++) {
		fill(distA[i], distA[i] + n, INF);
		fill(distB[i], distB[i] + n, INF);
		distA[i][i] = 0;
		distB[i][i] = 0;
	}

	while(k--){
		string t, a, b;
		int c;
		cin >> t >> a >> b >> c;
		c *= 2;
		int u = city_to_id[a];
		int v = city_to_id[b];

		c = min(c, distA[u][v]);
		distA[u][v] = distA[v][u] = c;

		if (t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun")
			c = 0;
		else if (t == "S-Train" || t == "V-Train")
			c /= 2;
		c = min(c, distB[u][v]);
		distB[u][v] = distB[v][u] = c;
	}

	for (int mid = 0; mid < cityCnt; mid++) {
		for (int st = 0; st < cityCnt; st++) {
			for (int ed = 0; ed < cityCnt; ed++) {
				distA[st][ed] = min(distA[st][ed], distA[st][mid] + distA[mid][ed]);
				distB[st][ed] = min(distB[st][ed], distB[st][mid] + distB[mid][ed]);
			}
		}
	}

	int costA = 0;
	int costB = 0;
	for (int i = 1; i < m; i++) {
		costA += distA[vis[i - 1]][vis[i]];
		costB += distB[vis[i - 1]][vis[i]];
	}

	if (costB + r*2 < costA)
		cout << "Yes";
	else
		cout << "No";
	return 0;

	/*
	문제 조건이 애매함. 
	1. 경로로 주어진 도시들을 순서대로 방문해야 함.
	2. 모든 교통 수단은 a->b, b->a로 이동 가능
	*/
}