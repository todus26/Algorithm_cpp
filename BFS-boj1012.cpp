//1012번 - 유기농 배추
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T, M, N, K;
int board[51][51];
bool vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        fill(&board[0][0], &board[50][51], 0);
        fill(&vis[0][0], &vis[50][51], false);

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1; // 배추가 있는 위치를 1로 표시
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j);
                    count++;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}