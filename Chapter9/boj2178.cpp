#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int maze[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // 이동 가능하고 아직 방문하지 않은 칸 (dist가 0이면 미방문)
            if (maze[nx][ny] == 1 && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - '0';
        }
    }
    
    cout << bfs() << '\n';
    
    return 0;
}