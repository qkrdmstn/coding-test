#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//a가 작을 때 참이어야 앞에 옴.
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(abs(a.first) == abs(b.first))
        return a.first > b.first;
    return abs(a.first)<abs(b.first);    
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    vector<pair<int, int>> DistIdxVector;
    for(int i=0; i<numlist.size(); i++)
        DistIdxVector.push_back({numlist[i] - n, i});
    sort(DistIdxVector.begin(), DistIdxVector.end(), cmp);
    
    for(int i=0; i<DistIdxVector.size(); i++)
    {
        answer.push_back(numlist[DistIdxVector[i].second]);        
    }
    
    return answer;
}