// 7569번 - 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, H; // M: 가로, N: 세로, H: 높이
int board[101][101][101]; // 3차원 배열로 토마토
bool vis[101][101][101]; // 방문 여부
int dx[6] = {1, 0, -1, 0, 0, 0}; // 상하좌우 위아래
int dy[6] = {0, 1, 0, -1, 0, 0}; // 상하좌우 위아래
int dz[6] = {0, 0, 0, 0, 1, -1}; // 상하좌우 위아래

void bfs(queue<pair<int, pair<int, int>>>& Q) {
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int z = cur.first; // 높이
        int x = cur.second.first; // 가로
        int y = cur.second.second; // 세로

        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nz][nx][ny] || board[nz][nx][ny] != 0) continue;

            vis[nz][nx][ny] = true;
            board[nz][nx][ny] = board[z][x][y] + 1; // 익은 토마토의 날짜를 기록
            Q.push({nz, {nx, ny}});
        }
    }
}

int main() {
    cin >> M >> N >> H;
    queue<pair<int, pair<int, int>>> Q;

    // 입력 받기
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> board[h][n][m];
                if (board[h][n][m] == 1) { // 익은 토마토 위치를 큐에 삽입
                    Q.push({h, {n, m}});
                    vis[h][n][m] = true; // 방문 처리
                }
            }
        }
    }

    bfs(Q); // BFS 시작

    int max_days = 0;
    bool all_ripe = true;

    // 결과 확인
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (board[h][n][m] == 0) { // 익지 않은 토마토가 있다면
                    all_ripe = false;
                } else {
                    max_days = max(max_days, board[h][n][m]);
                }
            }
        }
    }

    cout << (all_ripe ? max_days - 1 : -1) << endl; // 모든 토마토가 익었다면 최대 날짜 출력, 아니면 -1 출력

    return 0;
}