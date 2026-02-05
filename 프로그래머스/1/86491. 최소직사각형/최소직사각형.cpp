#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w = 0, h = 0;
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            w = max(sizes[i][0], w);
            h = max(sizes[i][1], h);
        }
        else
        {
            w = max(sizes[i][1], w);
            h = max(sizes[i][0], h);
        }
    }
    return w*h;
}