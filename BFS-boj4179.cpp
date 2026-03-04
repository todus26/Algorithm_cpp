#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char maze[1000][1000];
int fireTime[1000][1000];
int jihunTime[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue<pair<int, int>> fireQ;
pair<int, int> jihun;

void spreadFire() {
    while (!fireQ.empty()) {
        int x = fireQ.front().first;
        int y = fireQ.front().second;
        fireQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (maze[nx][ny] == '#') continue;
            if (fireTime[nx][ny] != -1) continue;
            
            fireTime[nx][ny] = fireTime[x][y] + 1;
            fireQ.push({nx, ny});
        }
    }
}

int escapeJihun() {
    queue<pair<int, int>> q;
    q.push(jihun);
    jihunTime[jihun.first][jihun.second] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 탈출 확인 (가장자리 도달)
        if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
            return jihunTime[x][y] + 1;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (maze[nx][ny] == '#') continue;
            if (jihunTime[nx][ny] != -1) continue;
            
            // 불이 번지기 전에 도착할 수 있는지 확인
            if (fireTime[nx][ny] != -1 && fireTime[nx][ny] <= jihunTime[x][y] + 1) continue;
            
            jihunTime[nx][ny] = jihunTime[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> R >> C;
    
    memset(fireTime, -1, sizeof(fireTime));
    memset(jihunTime, -1, sizeof(jihunTime));
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            
            if (maze[i][j] == 'F') {
                fireQ.push({i, j});
                fireTime[i][j] = 0;
            } else if (maze[i][j] == 'J') {
                jihun = {i, j};
            }
        }
    }
    
    // 불이 먼저 번진다
    spreadFire();
    
    // 지훈이 탈출 시도
    int result = escapeJihun();
    
    if (result == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}