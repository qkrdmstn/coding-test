#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 비용 오름차순으로 costs를 정렬
bool cmp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int find(int u, vector<int>& p)
{
    if(p[u] < 0) return u;
    return p[u] = find(p[u], p);
}

bool uni(int u, int v, vector<int>& p)
{
    u = find(u, p);
    v = find(v, p);
    if(u == v) return false;
    p[u] = v;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> p(n, -1);
    
    // costs를 비용 오름차순으로 정렬합니다.
    sort(costs.begin(), costs.end(), cmp);
    
    // 크루스칼 알고리즘을 활용해 최소신장트리를 구성합니다.
    int cnt = 0;
    for(const auto& cost: costs)
    {
        int u = cost[0], v = cost[1];
        int c = cost[2];
        if(uni(u, v, p))
        {
            cnt++;
            answer += c;
        }
        
        // 간선이 n-1개가 지정되면 크루스칼 알고리즘을 종료합니다.
        if(cnt == n-1) break;
    }
    return answer;
}