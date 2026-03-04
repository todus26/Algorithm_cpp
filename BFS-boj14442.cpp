#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
char map[1000][1000];
int visited[1000][1000][11]; // [x][y][벽을 부순 개수]

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct State {
    int x, y, broken, dist;
};

int bfs() {
    queue<State> q;
    q.push({0, 0, 0, 1});
    visited[0][0][0] = 1;
    
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        // 도착 확인
        if (cur.x == N - 1 && cur.y == M - 1) {
            return cur.dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            // 빈 칸으로 이동
            if (map[nx][ny] == '0') {
                if (visited[nx][ny][cur.broken] == 0) {
                    visited[nx][ny][cur.broken] = 1;
                    q.push({nx, ny, cur.broken, cur.dist + 1});
                }
            }
            // 벽을 부수고 이동
            else if (map[nx][ny] == '1') {
                if (cur.broken < K && visited[nx][ny][cur.broken + 1] == 0) {
                    visited[nx][ny][cur.broken + 1] = 1;
                    q.push({nx, ny, cur.broken + 1, cur.dist + 1});
                }
            }
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