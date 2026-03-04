// 10026번 - 적록색약
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; // 격자의 크기
char board[101][101]; // 격자판
bool vis[101][101]; // 방문 여부
int dx[4] = {1, 0, -1, 0}; // 상하좌우 네 방향을 의미
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미

void bfs(int startX, int startY, char color) {
    queue<pair<int, int>> Q;
    Q.push({startX, startY});
    vis[startX][startY] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != color) continue; // 이미 방문한 칸이거나 색상이 다를 경우

            vis[nx][ny] = true; // 방문 처리
            Q.push({nx, ny}); // 큐에 다음 위치 삽입
        }
    }
}

// 적록색약용 BFS - R과 G를 같은 색으로 처리
void bfs_colorblind(int startX, int startY, char color) {
    queue<pair<int, int>> Q;
    Q.push({startX, startY});
    vis[startX][startY] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny]) continue;

            // 적록색약: R과 G는 같은 색으로, B는 다른 색으로 처리
            bool same_color = false;
            if ((color == 'R' || color == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                same_color = true;
            } else if (color == 'B' && board[nx][ny] == 'B') {
                same_color = true;
            }

            if (!same_color) continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    cin >> N; // 격자의 크기 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j]; // 격자판 입력
        }
    }

    int normal_count = 0; // 일반인 기준 색 영역 개수
    fill(&vis[0][0], &vis[N][N], false); // 방문 배열 초기화

    // 일반인 기준 BFS
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                bfs(i, j, board[i][j]);
                normal_count++;
            }
        }
    }

    int colorblind_count = 0; // 적록색약 기준 색 영역 개수
    fill(&vis[0][0], &vis[N][N], false); // 방문 배열 초기화

    // 적록색약 기준 BFS
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                bfs_colorblind(i, j, board[i][j]);
                colorblind_count++;
            }
        }
    }

    cout << normal_count << " " << colorblind_count << endl; // 결과 출력
    return 0;
}