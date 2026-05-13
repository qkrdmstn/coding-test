#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& p)
{
    if(p[x] == -1) return x;
    return p[x] = find(p[x], p);
}

bool uni(int u, int v, vector<int>& p)
{
    u = find(u, p);
    v = find(v, p);
    if(u == v) return false;
    p[u] = v;
    return true;
}

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> p(n, -1);
    sort(costs.begin(), costs.end(), cmp);
    
    int cnt = 0;
    for(int i=0; i<costs.size(); i++)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        if(uni(a, b, p)) 
        {
            cnt++;
            answer += cost;
        }
        if(cnt == n-1) break;
    }
    return answer;
}