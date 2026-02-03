#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            int diffX1 = dots[i][0] - dots[j][0];
            int diffY1 = dots[i][1] - dots[j][1];
            for(int k=0; k<4; k++)
            {
                if(k == i || k == j) continue;
                for(int l=0; l<4; l++)
                {
                    if(l == i || l == j || l == k) continue;
                    int diffX2 = dots[k][0] - dots[l][0];
                    int diffY2 = dots[k][1] - dots[l][1];
                    
                    cout << i << j << k << l << " / " 
                        << diffX1 << " " << diffY1 << " "  << diffX2 << " "  << diffY2 << endl;
                    if(((float)diffX1/diffY1) == (float)((float)diffX2/diffY2))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}