#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct pos {
    int x1, x2, idx;
};

int n, q, ans, x1, x2, y;
int par[100001], sze[100001];
vector<pos> v;

bool cmp(pos a, pos b) {
    return a.x1 < b.x1;
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    v.push_back({ 0,0,0 });
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> x2 >> y;
        v.push_back({ x1,x2,i });
        par[i] = i;
        sze[i] = 1;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 1, j = 2; i <= n && j <= n;) {
        if (v[j].x1 <= v[i].x2) {
            merge(v[i].idx, v[j].idx);
            j++;
        }
        else i++;
    }

    for (int i = 0; i < q; i++) {
        cin >> x1 >> x2;
        if (find(x1) == find(x2)) cout << "1\n";
        else cout << "0\n";
    }
}
