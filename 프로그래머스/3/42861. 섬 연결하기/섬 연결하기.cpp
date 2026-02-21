#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int Find(int x, vector<int>& p)
{
    if(p[x] < 0)
        return x;
    return p[x] = Find(p[x], p);
}

bool IsDiffParent(int u, int v, vector<int>& p)
{
    u = Find(u, p);  
    v = Find(v, p);
    if(u==v) return false;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u; //u랭크가 더 높으면 v의 부모를 u로
    else p[u] = v; //반대라면, u의 부모를 v로
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<costs.size(); i++)
    {
        int u = costs[i][0], v = costs[i][1], c = costs[i][2];
        edges.push_back({c, u, v}); //{비용, 정점1, 정점2}
    }
    
    //비용 오름차순으로 정렬
    sort(edges.begin(), edges.end());

    vector<int> p(n + 1, -1);
    int cnt = 0;
    for(auto e: edges)
    {
        int c, u, v;
        tie(c, u, v) = e;
        if(!IsDiffParent(u, v, p)) continue;
        answer+=c;
        cnt++;
        if(cnt == n-1) break;
    }
    return answer;
}