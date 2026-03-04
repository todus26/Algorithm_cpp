// 14502번 - 연구소
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
int maxSafeArea = 0;

// 4방향 이동 (상, 하, 좌, 우)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// BFS로 바이러스 퍼뜨리고 안전 영역 계산
int calculateSafeArea() {
    // 임시 연구소 복사
    vector<vector<int>> tempLab = lab;
    
    // BFS로 바이러스 전파
    queue<pair<int, int>> q;
    for (auto& v : virus) {
        q.push(v);
    }
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // 범위 체크 및 빈 공간인지 확인
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && tempLab[nr][nc] == 0) {
                tempLab[nr][nc] = 2; // 바이러스 전파
                q.push({nr, nc});
            }
        }
    }
    
    // 안전 영역(빈 공간) 개수 계산
    int safeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempLab[i][j] == 0) {
                safeCount++;
            }
        }
    }
    
    return safeCount;
}

// 벽을 3개 세우는 모든 조합을 시도
void placeWalls(int depth, int start) {
    if (depth == 3) {
        // 3개의 벽을 모두 세웠으면 안전 영역 계산
        int safeArea = calculateSafeArea();
        maxSafeArea = max(maxSafeArea, safeArea);
        return;
    }
    
    // 가능한 모든 위치에 벽 세우기
    for (int i = start; i < n * m; i++) {
        int r = i / m;
        int c = i % m;
        
        if (lab[r][c] == 0) { // 빈 공간에만 벽 세우기
            lab[r][c] = 1; // 벽 세우기
            placeWalls(depth + 1, i + 1);
            lab[r][c] = 0; // 백트래킹 - 벽 제거
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    lab.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus.push_back({i, j}); // 바이러스 위치 저장
            }
        }
    }
    
    placeWalls(0, 0);
    
    cout << maxSafeArea << endl;
    
    return 0;
}