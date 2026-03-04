#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int map[100][100];
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int height) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && map[nx][ny] > height) {
                dfs(nx, ny, height);
            }
        }
    }
}

int countSafeArea(int height) {
    memset(visited, false, sizeof(visited));
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] > height) {
                dfs(i, j, height);
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            maxHeight = max(maxHeight, map[i][j]);
        }
    }
    
    int result = 1; // 비가 안 오는 경우 (height = 0)
    
    // 높이 1부터 maxHeight-1까지 확인
    for (int h = 1; h < maxHeight; h++) {
        int safeArea = countSafeArea(h);
        result = max(result, safeArea);
    }
    
    cout << result << "\n";
    
    return 0;
}
