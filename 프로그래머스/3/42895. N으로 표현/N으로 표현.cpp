#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    // 1. N을 i번 사용해서 만든 숫자들을 담을 집합(Set) 8개 생성
    // index 1부터 8까지 사용하기 위해 크기 9로 설정
    vector<unordered_set<long long>> s(9);

    // 2. 각 단계별 'N, NN, NNN...' 초기값 미리 삽입
    long long basic_num = 0;
    for (int i = 1; i <= 8; ++i) {
        basic_num = basic_num * 10 + N;
        s[i].insert(basic_num);
    }

    // 3. DP 진행: i번 사용해서 만들 수 있는 모든 경우의 수 계산
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j < i; ++j) { // j번 사용한 결과와 (i-j)번 사용한 결과 조합
            for (auto a : s[j]) {
                for (auto b : s[i - j]) {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0) s[i].insert(a / b);
                }
            }
        }
        
        // 4. 이번 단계에서 목표 숫자를 찾았는지 즉시 확인 (조기 종료)
        if (s[i].count(number)) return i;
    }

    return -1; // 8번 안에 못 찾으면 -1
}