#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    int r1 = arr1.size(), c1 = arr1[0].size();
    int c2 = arr2[0].size();
    
    vector<vector<int>> answer(r1, vector<int>(c2, 0));
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            for(int k=0; k<c1; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}