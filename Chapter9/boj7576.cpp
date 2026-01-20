#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
int box[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int bfs() {
    int days = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (box[nx][ny] != 0) continue;
                
                box[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        
        if (!q.empty()) days++;
    }
    
    // 모든 토마토가 익었는지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                return -1;
            }
        }
    }
    
    return days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            
            // 익은 토마토를 모두 큐에 넣음
            if (box[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    
    int result = bfs();
    
    cout << result << "\n";
    
    return 0;
}