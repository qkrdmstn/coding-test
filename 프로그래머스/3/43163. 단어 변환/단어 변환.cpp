#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool CheckChangePossible(string a, string b)
{
    int cnt = 0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

void BuildEdge(string begin, string target, int& beginIdx, int& targetIdx, vector<vector<int>>& edge, vector<string>& words)
{
    for(int i=0; i<words.size(); i++)
    {
        if(words[i] == begin) beginIdx = i;
        if(words[i] == target) targetIdx = i;
        for(int j=i; j<words.size(); j++)
        {
            if(i==j) continue;
            if(CheckChangePossible(words[i], words[j]))
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int beginIdx = -1;
    int targetIdx = -1;
    words.push_back(begin);
    vector<vector<int>> edge(words.size(), vector<int>());
    vector<int> dist(words.size(), -1);
    
    BuildEdge(begin, target, beginIdx, targetIdx, edge, words);
    if(targetIdx == -1) return 0;
    
    queue<int> q;
    q.push(beginIdx);
    dist[beginIdx] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == targetIdx) break;
        
        for(auto nxt: edge[cur])
        {
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    if(dist[targetIdx] < 0) return 0;
    return dist[targetIdx];
}