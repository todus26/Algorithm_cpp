#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int T;
int W, H;
char board[1001][1001];
int fire_time[1001][1001];  // 불이 도달하는 시간
int person_time[1001][1001]; // 사람이 도달하는 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fire_bfs(queue<pair<int, int>>& fire_q) {
    while (!fire_q.empty()) {
        auto cur = fire_q.front();
        fire_q.pop();
        int x = cur.first;
        int y = cur.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny] == '#') continue;
            if (fire_time[nx][ny] != -1) continue; // 이미 불이 도달했음
            
            fire_time[nx][ny] = fire_time[x][y] + 1;
            fire_q.push({nx, ny});
        }
    }
}

int person_bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    person_time[startX][startY] = 0;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        
        // 경계에 도달하면 탈출 성공
        if (x == 0 || x == H-1 || y == 0 || y == W-1) {
            return person_time[x][y] + 1;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny] == '#') continue;
            if (person_time[nx][ny] != -1) continue; // 이미 방문
            
            // 불이 도달하기 전에 갈 수 있는지 확인
            if (fire_time[nx][ny] != -1 && fire_time[nx][ny] <= person_time[x][y] + 1) {
                continue;
            }
            
            person_time[nx][ny] = person_time[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    return -1; // 탈출 불가능
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> W >> H;
        
        // 초기화
        memset(fire_time, -1, sizeof(fire_time));
        memset(person_time, -1, sizeof(person_time));
        
        queue<pair<int, int>> fire_q;
        int startX = -1, startY = -1;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
                
                if (board[i][j] == '@') {
                    startX = i;
                    startY = j;
                    board[i][j] = '.'; // 빈 공간으로 변경
                } else if (board[i][j] == '*') {
                    fire_q.push({i, j});
                    fire_time[i][j] = 0;
                }
            }
        }
        
        // 불 확산 시뮬레이션
        fire_bfs(fire_q);
        
        // 사람의 탈출 경로 탐색
        int result = person_bfs(startX, startY);
        
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << result << "\n";
        }
    }
    
    return 0;
}