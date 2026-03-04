#include <iostream>
using namespace std;

int N;
int cnt = 0;
int col[15]; // col[i] = i번째 행의 퀸이 놓인 열 위치

bool check(int row) {
    for(int i = 0; i < row; i++) {
        // 같은 열이거나 대각선에 있으면 안됨
        if(col[i] == col[row] || abs(col[i] - col[row]) == row - i) {
            return false;
        }
    }
    return true;
}

void nqueen(int row) {
    if(row == N) {
        cnt++;
        return;
    }
    
    for(int i = 0; i < N; i++) {
        col[row] = i;
        if(check(row)) {
            nqueen(row + 1);
        }
    }
}

int main() {
    cin >> N;
    nqueen(0);
    cout << cnt;
    return 0;
}