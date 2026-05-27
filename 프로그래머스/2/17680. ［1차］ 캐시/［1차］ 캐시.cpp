#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    for(auto& city: cities)
    {
        for(auto& c: city)
            c = tolower(c);
        
        auto it = find(cache.begin(), cache.end(), city);
        // cache miss.
        if(it == cache.end())
        {
            answer+=5;
            cache.push_back(city);
            if(cache.size() > cacheSize)
                cache.pop_front();
        }
        // cache hit
        else
        {
            answer += 1;
            cache.erase(it);
            cache.push_back(city);
        }
    }
    return answer;
}