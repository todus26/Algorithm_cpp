// 16985번 - Maaaaaaze
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int original[5][5][5];
int maze[5][5][5];
int minSteps = 1e9;

// 6방향 이동 (위, 아래, 앞, 뒤, 왼쪽, 오른쪽)
int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};

// 판을 시계방향으로 90도 회전
void rotate90(int board[5][5], int rotated[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            rotated[j][4-i] = board[i][j];
        }
    }
}

// BFS로 최단 경로 찾기
int bfs() {
    // 시작점과 끝점이 막혀있으면 불가능
    if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return -1;
    
    queue<tuple<int, int, int, int>> q; // z, y, x, steps
    bool visited[5][5][5];
    memset(visited, false, sizeof(visited));
    
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        auto [z, y, x, steps] = q.front();
        q.pop();
        
        if (z == 4 && y == 4 && x == 4) {
            return steps;
        }
        
        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if (nz >= 0 && nz < 5 && ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
                if (!visited[nz][ny][nx] && maze[nz][ny][nx] == 1) {
                    visited[nz][ny][nx] = true;
                    q.push({nz, ny, nx, steps + 1});
                }
            }
        }
    }
    
    return -1; // 도달 불가능
}

// 순열과 회전을 모두 시도
void solve(vector<int>& order, vector<int>& rotation, int depth) {
    if (depth == 5) {
        // 현재 순열과 회전 상태로 미로 구성
        for (int i = 0; i < 5; i++) {
            int level = order[i];
            int rot = rotation[i];
            
            // 원본을 복사
            int temp[5][5];
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    temp[j][k] = original[level][j][k];
                }
            }
            
            // rot번 회전
            for (int r = 0; r < rot; r++) {
                int rotated[5][5];
                rotate90(temp, rotated);
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        temp[j][k] = rotated[j][k];
                    }
                }
            }
            
            // 미로에 배치
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    maze[i][j][k] = temp[j][k];
                }
            }
        }
        
        // BFS로 최단 경로 찾기
        int result = bfs();
        if (result != -1) {
            minSteps = min(minSteps, result);
        }
        return;
    }
    
    // 다음 레벨 선택 (순열)
    for (int i = 0; i < 5; i++) {
        bool used = false;
        for (int j = 0; j < depth; j++) {
            if (order[j] == i) {
                used = true;
                break;
            }
        }
        
        if (!used) {
            order[depth] = i;
            
            // 4가지 회전 상태 시도
            for (int rot = 0; rot < 4; rot++) {
                rotation[depth] = rot;
                solve(order, rotation, depth + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> original[i][j][k];
            }
        }
    }
    
    vector<int> order(5);
    vector<int> rotation(5);
    
    solve(order, rotation, 0);
    
    if (minSteps == 1e9) {
        cout << -1 << endl;
    } else {
        cout << minSteps << endl;
    }
    
    return 0;
}