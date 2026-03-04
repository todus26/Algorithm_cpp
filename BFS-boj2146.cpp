#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int board[100][100];
bool visited[100][100];
int island_id[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 각 섬에 고유한 번호를 부여하는 함수
void label_islands(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    island_id[x][y] = id;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || board[nx][ny] == 0) continue;
            
            visited[nx][ny] = true;
            island_id[nx][ny] = id;
            q.push({nx, ny});
        }
    }
}

// 특정 섬에서 다른 섬까지의 최단 거리를 구하는 함수
int find_shortest_bridge(int start_id) {
    queue<pair<pair<int, int>, int>> q; // {{x, y}, distance}
    bool vis[100][100];
    memset(vis, false, sizeof(vis));
    
    // 시작 섬의 모든 경계 지점을 큐에 추가
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (island_id[i][j] == start_id) {
                // 인접한 곳에 바다가 있으면 경계
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == 0) {
                        q.push({{i, j}, 0});
                        vis[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int dist = cur.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny]) continue;
            
            // 다른 섬에 도달한 경우
            if (board[nx][ny] == 1 && island_id[nx][ny] != start_id) {
                return dist;
            }
            
            // 바다인 경우만 계속 진행
            if (board[nx][ny] == 0) {
                vis[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
    
    return 987654321; // 도달할 수 없는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    // 각 섬에 고유한 번호 부여
    memset(visited, false, sizeof(visited));
    memset(island_id, 0, sizeof(island_id));
    
    int island_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                island_count++;
                label_islands(i, j, island_count);
            }
        }
    }
    
    // 각 섬에서 다른 섬까지의 최단 거리 계산
    int answer = 987654321;
    for (int id = 1; id <= island_count; id++) {
        int bridge_length = find_shortest_bridge(id);
        answer = min(answer, bridge_length);
    }
    
    cout << answer << endl;
    
    return 0;
}