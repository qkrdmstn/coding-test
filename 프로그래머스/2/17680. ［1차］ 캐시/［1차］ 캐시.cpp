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
        // 대소문자를 구분하지 않기 위해 모든 도시를 소문자로 변경합니다.
        for(auto& c: city)
            c = tolower(c);
        
        // 현재 도시가 캐싱되어있는지 확인합니다.
        auto it = find(cache.begin(), cache.end(), city);
       
        // 캐시 미스
        if(it == cache.end())
        {
            answer += 5;
            // 현재 도시를 캐싱하고, 캐시 사이즈를 조정합니다.
            cache.push_back(city);
            if(cache.size() > cacheSize)
                cache.pop_front();
        }
        // 캐시 히트
        else
        {
            answer += 1;
            // 현재 도시를 캐시에서 최신화합니다. (LRU)
            cache.erase(it);
            cache.push_back(city);
        }
    }
    return answer;
}