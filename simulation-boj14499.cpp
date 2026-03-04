// 14499번 - 주사위 굴리기

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> board(n, vector<int>(m));
    vector<int> dice(6, 0); // 주사위의 각 면을 저장
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    vector<int> commands(k);    
    for (int i = 0; i < k; ++i) {
        cin >> commands[i];
    }
    // 주사위의 방향을 정의
    int dx[] = {0, 0, 0, -1, 1}; // 동, 서, 북, 남
    int dy[] = {0, 1, -1, 0, 0}; // 동, 서, 북, 남  
    for (int cmd : commands) {
        int nx = x + dx[cmd];
        int ny = y + dy[cmd];   
        // 이동할 위치가 범위 내에 있는지 확인
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        // 주사위 굴리기
        if (cmd == 1) { // 동쪽으로 굴리기
            int temp = dice[0];     
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        }
        else if (cmd == 2) { // 서쪽으로 굴리기
            int temp = dice[0];
            dice[0] = dice[1];      
            dice[1] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
        }   
        else if (cmd == 3) { // 북쪽으로 굴리기
            int temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
        }   
        else if (cmd == 4) { // 남쪽으로 굴리기
            int temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
        }
        // 이동 후 주사위 위치 업데이트
        x = nx;
        y = ny;
        // 이동한 칸의 값에 따라 주사위의 바닥면 값 설정
        if (board[x][y] == 0) {
            board[x][y] = dice[5]; // 바닥면 값이 0이면 주사위의 바닥면 값을 칸에 복사
        }
        else {
            dice[5] = board[x][y]; // 바닥면 값이 0이 아니면 칸의 값을 주사위의 바닥면에 복사
            board[x][y] = 0; // 칸의 값을 0으로 설정
        }
        // 주사위의 윗면 값 출력
        cout << dice[0] << endl;
    }
    return 0;
}
