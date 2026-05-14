#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int len, vector<string>& words, vector<bool>& used, vector<string>& word, unordered_set<string>& res)
{
    if(word.size() == len)
    {
        string s = "";
        for(auto& w: word)
            s += w;
        res.insert(s);
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        if(used[i]) continue;
        used[i] = true;
        word.push_back(words[i]);
        dfs(len, words, used, word, res);
        used[i] = false;
        word.pop_back();
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> words = {"aya", "ye", "woo", "ma"};
    unordered_set<string> res;
    for(int i=1; i<=4; i++)
    {
        vector<bool> used(words.size(), false);
        vector<string> word;
        dfs(i, words, used, word, res);
    }
    
    for(string& b: babbling)
    {
        if(res.find(b) != res.end()) answer++;
    }
    return answer;
}