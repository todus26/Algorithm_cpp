#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int, int>> switches[101][101];
bool lightOn[101][101];
bool visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool canReach(int x, int y) {
    // (x, y)에 인접한 칸 중 방문 가능한 칸이 있는지 확인
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            if (visited[nx][ny]) {
                return true;
            }
        }
    }
    return false;
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    lightOn[1][1] = true;
    
    int count = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 현재 위치에서 켤 수 있는 모든 불 켜기
        for (auto light : switches[x][y]) {
            int lx = light.first;
            int ly = light.second;
            
            if (!lightOn[lx][ly]) {
                lightOn[lx][ly] = true;
                count++;
                
                // 새로 켠 방이 이미 방문 가능한 위치라면 큐에 추가
                if (canReach(lx, ly) && !visited[lx][ly]) {
                    visited[lx][ly] = true;
                    q.push({lx, ly});
                }
            }
        }
        
        // 4방향 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visited[nx][ny]) continue;
            if (!lightOn[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }
    
    int result = bfs();
    cout << result << "\n";
    
    return 0;
}