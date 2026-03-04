// 15684번 - 사다리 조작
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H;
int ladder[31][11]; // ladder[h][n]: h번째 가로선에서 n번 세로선과 n+1번 세로선 연결 여부
int answer = 4;

bool check() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int h = 1; h <= H; h++) {
            if (ladder[h][pos] == 1) {
                pos++;
            } else if (pos > 1 && ladder[h][pos - 1] == 1) {
                pos--;
            }
        }
        if (pos != i) return false;
    }
    return true;
}

void dfs(int count, int maxCount, int startH) {
    if (count == maxCount) {
        if (check()) {
            answer = min(answer, maxCount);
        }
        return;
    }
    
    // 이미 답을 찾았으면 더 탐색할 필요 없음
    if (answer <= maxCount) return;
    
    for (int h = startH; h <= H; h++) {
        for (int n = 1; n < N; n++) {
            // 현재 위치에 사다리를 놓을 수 있는지 확인
            if (ladder[h][n] == 0) {
                // 왼쪽과 오른쪽에 사다리가 없어야 함
                bool canPlace = true;
                if (n > 1 && ladder[h][n - 1] == 1) canPlace = false;
                if (n < N - 1 && ladder[h][n + 1] == 1) canPlace = false;
                
                if (canPlace) {
                    ladder[h][n] = 1;
                    dfs(count + 1, maxCount, h);
                    ladder[h][n] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> H;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    
    // 사다리를 0개부터 3개까지 추가해보기
    for (int i = 0; i <= 3; i++) {
        dfs(0, i, 1);
        if (answer != 4) {
            cout << answer << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}