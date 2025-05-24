#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 500 + 5;
vector<int> adj[MAX];
bool vis[MAX];

bool isTree(int start) {
    queue<pair<int, int>> q; // (현재 노드, 부모 노드)
    q.push({start, 0});
    vis[start] = true;

    while (!q.empty()) {
        auto [cur, par] = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (nxt == par) continue; // 부모 노드는 패스
            if (vis[nxt]) return false; // 이미 방문한데 또 방문 = 사이클
            vis[nxt] = true;
            q.push({nxt, cur});
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            vis[i] = false;
        }

        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && isTree(i))
                treeCount++;
        }

        cout << "Case " << t++ << ": ";
        if (treeCount == 0) cout << "No trees.\n";
        else if (treeCount == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << treeCount << " trees.\n";
    }
    return 0;
}
