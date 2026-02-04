#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

//조건 2, 3번에 따른 정렬 순서 비교 함수입니다.
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b. first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> totalOfGenres; // {장르, 총 재생 횟수}
    map<int, string> genresOfTotal; // {총 재생 횟수, 장르}
    map<string, vector<pair<int, int>>> musicOfGenres; //{장르, {재생 횟수, 고유 번호}}
    
    //각각 {장르, 총 재생 수}, {장르, 음악 vector} hash를 저장합니다.
    for(int i=0; i<genres.size(); i++)
    {
        totalOfGenres[genres[i]] += plays[i];
        musicOfGenres[genres[i]].push_back({plays[i], i});
    }
    
    //{총 재생 수, 장르} hash를 저장합니다.
    for(auto m: totalOfGenres)
        genresOfTotal[m.second] = m.first;
    
    //장르별 총 재생 횟수를 오름차순으로 저장합니다.
    vector<string> orderOfGenres;
    for(auto m: genresOfTotal)
        orderOfGenres.push_back(m.second);
    
    //각 장르에 속한 음악을 재생 수 내림차 순으로 정렬합니다.
    for(auto &m: musicOfGenres)
        sort(m.second.begin(), m.second.end(), cmp);
    
    for(int i=orderOfGenres.size()-1; i>=0; i--)
    {
        vector<pair<int, int>> &curGenres = musicOfGenres[orderOfGenres[i]];
        for(int j=0; j < min(2, (int)curGenres.size()); j++)
            answer.push_back(curGenres[j].second);
    }
        
    return answer;
}