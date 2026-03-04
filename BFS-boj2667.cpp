#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && map[nx][ny] == 1) {
                count += dfs(nx, ny);
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    // 지도 입력
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j] - '0';
        }
    }
    
    vector<int> complexes;
    
    // 단지 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int houseCount = dfs(i, j);
                complexes.push_back(houseCount);
            }
        }
    }
    
    // 결과 정렬 및 출력
    sort(complexes.begin(), complexes.end());
    
    cout << complexes.size() << "\n";
    for (int count : complexes) {
        cout << count << "\n";
    }
    
    return 0;
}