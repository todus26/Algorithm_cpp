#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int map[100][100];
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int area = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && map[nx][ny] == 0) {
                area += dfs(nx, ny);
            }
        }
    }
    
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n >> k;
    
    // 직사각형 그리기
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // (x1, y1)부터 (x2, y2)까지 직사각형 칠하기
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                map[y][x] = 1;
            }
        }
    }
    
    vector<int> areas;
    
    // 빈 영역 찾기
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 0) {
                int area = dfs(i, j);
                areas.push_back(area);
            }
        }
    }
    
    // 결과 출력
    sort(areas.begin(), areas.end());
    
    cout << areas.size() << "\n";
    for (int area : areas) {
        cout << area << " ";
    }
    cout << "\n";
    
    return 0;
}