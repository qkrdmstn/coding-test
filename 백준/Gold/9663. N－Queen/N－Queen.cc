#include <iostream>
#include <vector>
using namespace std;

void DFS(int cur, int cnt, vector<bool>& used1, vector<bool>& used2, vector<bool>& used3, int n, int& ans)
{
	if (cur == n)
	{
		if(cnt==n)
			ans++;
		return;
	}

	//행 순회
	for (int i = 0; i < n; i++)
	{
		int idx2 = cur+i;
		int idx3 = cur - i + (n-1);
		if(used1[i] || used2[idx2] || used3[idx3]) continue;
		used1[i] = true;
		used2[idx2] = true;
		used3[idx3] = true;
		DFS(cur+1, cnt+1, used1, used2, used3, n, ans);
		used1[i] = false;
		used2[idx2] = false;
		used3[idx3] = false;
	}
}

int main(void)
{

	int n;
	cin >> n;
	vector<bool> used1(n,false); //행 사용 여부
	vector<bool> used2(2*n-1,false); //오른쪽 위 방향 대각선
	vector<bool> used3(2*n-1,false); //오른쪽 아래 방향 대각선

	int ans = 0;
	DFS(0, 0, used1, used2,used3, n, ans);
	cout << ans;
	return 0;
}