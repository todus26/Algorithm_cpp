// 7562번 - 나이트의 이동
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int L; // 체스판의 크기
int board[301][301]; // 이동 횟수를 저장할 배열
bool vis[301][301]; // 방문 여부
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // 나이트의 이동 방향
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // 나이트의 이동 방향

void bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> Q;
    Q.push({startX, startY});
    vis[startX][startY] = true;
    board[startX][startY] = 0; // 시작 위치의 이동 횟수는 0

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;

        if (x == endX && y == endY) {
            cout << board[x][y] << endl; // 도착 위치에 도달하면 이동 횟수 출력
            return;
        }

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny]) continue; // 이미 방문한 칸은 넘어감

            vis[nx][ny] = true; // 방문 처리
            board[nx][ny] = board[x][y] + 1; // 이동 횟수 기록
            Q.push({nx, ny}); // 큐에 다음 위치 삽입
        }
    }
}

int main() {
    int T; // 테스트 케이스 수
    cin >> T;
    while (T--) {
        cin >> L; // 체스판의 크기
        int startX, startY, endX, endY;
        cin >> startX >> startY; // 시작 위치
        cin >> endX >> endY; // 도착 위치

        // 초기화
        fill(&board[0][0], &board[L][L], -1);
        fill(&vis[0][0], &vis[L][L], false);

        bfs(startX, startY, endX, endY); // BFS 실행
    }
    return 0;
}