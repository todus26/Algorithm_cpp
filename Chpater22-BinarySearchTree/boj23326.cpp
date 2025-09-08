// boj23326.cpp - 홍익 투어리스트 
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    set<int> attractions; // 명소인 구역들
    int current_pos = 1; // 현재 위치
    
    // 초기 명소 입력
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            attractions.insert(i);
        }
    }
    
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        
        if (query == 1) {
            int area;
            cin >> area;
            // 명소 상태 토글
            if (attractions.find(area) != attractions.end()) {
                attractions.erase(area); // 명소 해제
            } else {
                attractions.insert(area); // 명소로 지정
            }
        } else if (query == 2) {
            int x;
            cin >> x;
            // 시계방향으로 x만큼 이동 (원형이므로 N으로 나눈 나머지)
            current_pos = (current_pos + x - 1) % N + 1;
        } else if (query == 3) {
            if (attractions.empty()) {
                cout << -1 << '\n';
            } else {
                // 현재 위치에서 가장 가까운 명소 찾기
                auto it = attractions.lower_bound(current_pos);
                int distance;
                
                if (it != attractions.end()) {
                    // 현재 위치 이후에 명소가 있음
                    distance = *it - current_pos;
                } else {
                    // 현재 위치 이후에 명소가 없으므로 첫 번째 명소로 돌아감 (원형)
                    distance = N - current_pos + *attractions.begin();
                }
                cout << distance << '\n';
            }
        }
    }
    
    return 0;
}