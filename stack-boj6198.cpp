// 6198번 - 옥상 정원 꾸미기
#include <iostream>
#include <stack>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    stack<pair<int, int>> S; // (높이, 개수)
    long long ans = 0; // 결과 변수
    
    while (n--) {
        int h;
        cin >> h;
        int cnt = 1; // 현재 높이의 개수
        
        // 스택에서 현재 높이보다 작거나 같은 건물 제거
        while (!S.empty() && S.top().X <= h) {
            ans += S.top().Y; // 제거된 건물의 개수를 결과에 추가
            if (S.top().X == h) cnt += S.top().Y; // 같은 높이의 건물이 있다면 개수 증가
            S.pop();
        }
        
        if (!S.empty()) ans++; // 현재 건물보다 높은 건물이 있다면, 그 건물과 연결 가능
        
        S.push({h, cnt}); // 현재 건물 높이와 개수를 스택에 추가
    }
    
    cout << ans; // 결과 출력
    return 0;
}