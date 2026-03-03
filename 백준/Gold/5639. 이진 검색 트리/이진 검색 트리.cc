#include <iostream>
#include <vector>
using namespace std;

void postorder(int st, int ed, vector<int>& pre)
{
	if(st >= ed) return;
	int root = pre[st];

	int idx = st + 1;
	while (idx < ed && pre[idx] < root)
		idx++;
	
	//왼쪽 서브 트리 방문
	postorder(st + 1, idx, pre);
	//오른쪽 서브 트리 방문
	postorder(idx, ed, pre);
	//루트 출력
	cout << root << "\n";
}

int main(void)
{

	int n;
	vector<int> preorder;
	while (cin >> n)
		preorder.push_back(n);
	postorder(0, preorder.size(), preorder);
	return 0;
}