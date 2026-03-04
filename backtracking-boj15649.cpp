#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool used[9];

void backtrack(int depth) {
    if (depth == M) {
        // M개를 모두 선택했으면 출력
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            arr[depth] = i;
            used[i] = true;
            backtrack(depth + 1);
            used[i] = false; // 백트래킹
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    backtrack(0);
    
    return 0;
}