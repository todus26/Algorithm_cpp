#include <iostream>
using namespace std;

int count = 0;

void hanoi(int n, int from, int to, int via) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        count++;
        return;
    }
    
    // 1단계: n-1개의 원판을 from에서 via로 이동 (to를 경유)
    hanoi(n - 1, from, via, to);
    
    // 2단계: 가장 큰 원판을 from에서 to로 이동
    cout << from << " " << to << "\n";
    count++;
    
    // 3단계: n-1개의 원판을 via에서 to로 이동 (from을 경유)
    hanoi(n - 1, via, to, from);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 총 이동 횟수는 2^N - 1
    int totalMoves = (1 << N) - 1;
    cout << totalMoves << "\n";
    
    hanoi(N, 1, 3, 2);
    
    return 0;
}