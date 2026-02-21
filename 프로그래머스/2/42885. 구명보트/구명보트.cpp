#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int target, int start, vector<bool>& used, vector<int>& people)
{
    int end = people.size() - 1;
    while(start < end)
    {
        int mid = (start + end + 1) / 2;
        if(people[mid] <= target)
            start = mid;
        else
            end = mid - 1;
    }
    //이미 구출된 사람인 경우 더 가벼운 사람을 구출
    while(used[start] && start >= 0)
        start--;
    return start;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<bool> used(people.size(), false);
    sort(people.begin(), people.end());
    
    //1. 가벼운 사람을 고른 뒤, limit을 넘지 않는 무거운 사람을 이분탐색 합니다.
    for(int i=0; i<people.size(); i++)
    {
        if(used[i]) continue;
        answer++;
        used[i] = true;
        int target = BinarySearch(limit - people[i], i+1, used, people);
        //2. 만일 고를 사람이 없거나, 무게 제한을 넘길 경우 한 명만 구출합니다.
        if(target < 0 || people[i] + people[target] > limit) continue;
        used[target] = true;
    }
    return answer;
}