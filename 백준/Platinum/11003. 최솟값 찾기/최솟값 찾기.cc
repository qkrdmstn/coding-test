#include<iostream>
#include<deque>
using namespace std;

deque<pair<int, int>> dq;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        while (!dq.empty() && dq.back().first >= a)
            dq.pop_back();

        dq.push_back({ a, i });

        if (dq.front().second < i - l + 1)
            dq.pop_front();

        cout << dq.front().first << " ";
    }

    /*
    크게 두 가지로 나눠서 생각할 수 있다.
        1. deque에 push_back으로 삽입할 때, 스택과 유사한 방식으로 나보다 큰 애들은 다 pop_back을 진행하여 front엔 최소 값만 남도록 한다.
        2. 현재 값을 push한 뒤, front의 범위가 i-l+1 범위 바깥이라면 앞에서도 pop_front를 진행한다.
        -> 결론적으로 맨 앞의 값은 2에 의해 범위 내로 한정되며, 1에 의해 최소 값을 가진다.
    */
    return 0;
}