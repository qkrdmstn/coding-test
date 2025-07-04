#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sortBy, extBy;
int GetIndexOfValue(string str)
{
    if(str == "code")
        return 0;
    else if(str == "date")
        return 1;
    else if(str == "maximum")
        return 2;
    else if(str == "remain")
        return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    sortBy = GetIndexOfValue(sort_by);
    extBy = GetIndexOfValue(ext);
    
    for(int i=0; i<data.size(); i++){
        if(data[i][extBy] < val_ext)
            answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b)
                                    {return a[sortBy] < b[sortBy];});
    return answer;
}