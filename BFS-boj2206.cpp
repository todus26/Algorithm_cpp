#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct State {
    int x, y, dist, wall_broken;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<string> map(N);
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    // visited[x][y][wall_broken] - wall_broken: 0(벽을 안부숨), 1(벽을 부숨)
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    
    queue<State> q;
    q.push({0, 0, 1, 0}); // 시작점 (0,0), 거리 1, 벽 안부숨
    visited[0][0][0] = true;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        // 도착점에 도달했을 경우
        if (curr.x == N - 1 && curr.y == M - 1) {
            cout << curr.dist << endl;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            // 빈 공간인 경우
            if (map[nx][ny] == '0') {
                if (!visited[nx][ny][curr.wall_broken]) {
                    visited[nx][ny][curr.wall_broken] = true;
                    q.push({nx, ny, curr.dist + 1, curr.wall_broken});
                }
            }
            // 벽인 경우
            else if (map[nx][ny] == '1') {
                // 아직 벽을 부수지 않았다면 벽을 부수고 이동
                if (curr.wall_broken == 0 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, curr.dist + 1, 1});
                }
            }
        }
    }
    
    // 도착할 수 없는 경우
    cout << -1 << endl;
    return 0;
}