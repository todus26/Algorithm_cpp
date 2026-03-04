#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
char map[1000][1000];
int visited[1000][1000][11][2]; // [x][y][벽을 부순 개수][낮/밤]

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct State {
    int x, y, broken, dist, isDay;
};

int bfs() {
    queue<State> q;
    q.push({0, 0, 0, 1, 1}); // 시작은 낮(1)
    visited[0][0][0][1] = 1;
    
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        // 도착 확인
        if (cur.x == N - 1 && cur.y == M - 1) {
            return cur.dist;
        }
        
        int nextDay = 1 - cur.isDay; // 낮/밤 전환
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            // 빈 칸으로 이동 (낮/밤 상관없이 가능)
            if (map[nx][ny] == '0') {
                if (visited[nx][ny][cur.broken][nextDay] == 0) {
                    visited[nx][ny][cur.broken][nextDay] = 1;
                    q.push({nx, ny, cur.broken, cur.dist + 1, nextDay});
                }
            }
            // 벽을 부수고 이동 (낮에만 가능)
            else if (map[nx][ny] == '1') {
                if (cur.isDay && cur.broken < K) {
                    if (visited[nx][ny][cur.broken + 1][nextDay] == 0) {
                        visited[nx][ny][cur.broken + 1][nextDay] = 1;
                        q.push({nx, ny, cur.broken + 1, cur.dist + 1, nextDay});
                    }
                }
            }
        }
        
        // 제자리에서 대기 (낮/밤 전환)
        if (visited[cur.x][cur.y][cur.broken][nextDay] == 0) {
            visited[cur.x][cur.y][cur.broken][nextDay] = 1;
            q.push({cur.x, cur.y, cur.broken, cur.dist + 1, nextDay});
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    int result = bfs();
    cout << result << "\n";
    
    return 0;
}