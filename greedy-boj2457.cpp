// 2457번 - 공주님의 정원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Flower {
    int start;
    int end;
};

bool compare(const Flower &a, const Flower &b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end > b.end;
}

int main() {
    int N;
    cin >> N;
    
    vector<Flower> flowers(N);
    
    for (int i = 0; i < N; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        
        // 날짜를 숫자로 변환 (예: 3월 1일 -> 301)
        flowers[i].start = sm * 100 + sd;
        flowers[i].end = em * 100 + ed;
    }
    
    // 시작일 기준 오름차순, 같으면 종료일 기준 내림차순 정렬
    sort(flowers.begin(), flowers.end(), compare);
    
    int target = 301;  // 3월 1일부터 시작
    int maxEnd = 0;    // 현재까지 고려한 꽃들 중 가장 늦게 지는 날
    int count = 0;     // 선택한 꽃의 개수
    int idx = 0;       // 현재 검사 중인 꽃의 인덱스
    
    while (target < 1201) {  // 11월 30일까지 커버해야 함
        bool found = false;
        maxEnd = target;
        
        // 현재 target 이전에 피는 꽃들 중 가장 늦게 지는 꽃 찾기
        while (idx < N && flowers[idx].start <= target) {
            if (flowers[idx].end > maxEnd) {
                maxEnd = flowers[idx].end;
                found = true;
            }
            idx++;
        }
        
        if (!found) {
            // 현재 target을 커버할 수 있는 꽃이 없음
            cout << 0 << endl;
            return 0;
        }
        
        count++;
        target = maxEnd;  // 다음 target은 선택한 꽃이 지는 날
    }
    
    cout << count << endl;
    
    return 0;
}