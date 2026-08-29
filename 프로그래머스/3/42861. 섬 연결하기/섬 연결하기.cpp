#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[2] < b[2];
}

int find(int x, vector<int>& p)
{
    // 탐색하면서 거친 노트를 모두 해당 그룹의 루트 노드에 연결합니다.
    if(p[x] < 0) return x;
    return p[x] = find(p[x], p);
}

bool uni(int a, int b, vector<int>& p)
{
    a = find(a, p);
    b = find(b, p);
    
    if(a == b) return false;
    // 트리의 높이를 최대한 낮게 유지하기 위해 높이가 높은 것에 낮은 것을 연결합니다.
    if(p[a] < p[b])
        p[b] = a;
    else
        p[a] = b;
    return true;    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 각 그룹의 루트를 나타내는 배열입니다.
    vector<int> p(n, -1);
    
    // 간선을 비용 오름차순으로 정렬합니다.
    sort(costs.begin(), costs.end(), cmp);
    
    int cnt = 0;
    for(const auto& c: costs)
    {
        if(!uni(c[0], c[1], p)) continue;
        answer += c[2];
        cnt++;
        if(cnt == n-1) break;
    }
    return answer;
}