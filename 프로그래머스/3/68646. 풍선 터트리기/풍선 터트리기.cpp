#include <string>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int solution(vector<int> a) {
    int answer = 0;
    
    int n = a.size();
    vector<int> rmin(n, INF);
    vector<int> lmin(n, INF);
    
    lmin[0] = a[0];
    rmin[n-1] = a[n-1];
    for(int i=1; i<n; i++)
    {
        lmin[i] = min(a[i], lmin[i-1]);
        rmin[n-1-i] = min(a[n-1-i], rmin[n-i]);
    }
    for(int i=1; i<n-1; i++)
    {
        if(lmin[i-1] > a[i] || rmin[i+1] > a[i]) answer++;
    }
    return answer+2;
}