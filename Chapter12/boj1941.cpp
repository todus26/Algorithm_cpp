// 1941 - 소문난 칠공주
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> board(5, vector<char>(5));
int result = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 선택된 7개 위치가 모두 연결되어 있는지 확인
bool isConnected(vector<pair<int, int>>& selected) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<vector<bool>> isSelected(5, vector<bool>(5, false));
    
    // 선택된 위치들을 표시
    for (auto& pos : selected) {
        isSelected[pos.first][pos.second] = true;
    }
    
    // 첫 번째 선택된 위치에서 BFS 시작
    queue<pair<int, int>> q;
    q.push(selected[0]);
    visited[selected[0].first][selected[0].second] = true;
    int count = 1;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && 
                !visited[nx][ny] && isSelected[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
    
    return count == 7;  // 7개가 모두 연결되어 있는지 확인
}

// 25개 위치 중 7개를 선택하는 조합 생성
void dfs(vector<pair<int, int>>& selected, int start, int somCount) {
    if (selected.size() == 7) {
        // 이다솜파가 4명 이상이고 모두 연결되어 있으면 카운트
        if (somCount >= 4 && isConnected(selected)) {
            result++;
        }
        return;
    }
    
    for (int i = start; i < 25; i++) {
        int x = i / 5;
        int y = i % 5;
        
        selected.push_back({x, y});
        
        int newSomCount = somCount;
        if (board[x][y] == 'S') {
            newSomCount++;
        }
        
        dfs(selected, i + 1, newSomCount);
        selected.pop_back();
    }
}

int main() {
    // 5x5 격자 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    vector<pair<int, int>> selected;
    dfs(selected, 0, 0);
    
    cout << result << "\n";
    
    return 0;
}