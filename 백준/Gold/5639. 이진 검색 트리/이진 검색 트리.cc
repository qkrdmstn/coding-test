#include <iostream>
#include <vector>
using namespace std;

void postorder(int st, int ed, vector<int>& preorder)
{
    // st >= ed면 자식이 없는 노드에 도달.
	if(st>=ed) return;

	int root = preorder[st];
	int idx = st;
    //루트보다 큰 값을 찾을 때까지 전진
	while (idx < ed)
	{
		if(preorder[idx] > root) break;
		idx++;
	}
	postorder(st+1, idx, preorder);
	postorder(idx, ed, preorder);
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