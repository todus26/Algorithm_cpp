#include <iostream>
using namespace std;

int N, r, c;
int result = 0;

void solve(int size, int x, int y) {
    if (x == r && y == c) {
        cout << result << "\n";
        return;
    }
    
    // 목표 지점이 현재 영역 내에 있는 경우
    if (r >= x && r < x + size && c >= y && c < y + size) {
        int half = size / 2;
        
        // 4개의 사분면으로 나누어 탐색
        // 1사분면 (왼쪽 위)
        solve(half, x, y);
        
        // 2사분면 (오른쪽 위)
        solve(half, x, y + half);
        
        // 3사분면 (왼쪽 아래)
        solve(half, x + half, y);
        
        // 4사분면 (오른쪽 아래)
        solve(half, x + half, y + half);
    } else {
        // 목표 지점이 현재 영역 밖이면 해당 영역 전체를 건너뜀
        result += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> r >> c;
    
    int size = 1 << N; // 2^N
    solve(size, 0, 0);
    
    return 0;
}