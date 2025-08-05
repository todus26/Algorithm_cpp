// 14500번 - 테트로미노
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];
int maxSum = 0;

// 4방향 이동
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// DFS로 4개 블록을 선택하는 모든 경우 탐색 (ㅗ 모양 제외)
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        maxSum = max(maxSum, sum);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, sum + board[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

// ㅗ 모양과 그 회전된 형태들을 직접 확인
void checkTShape(int x, int y) {
    // ㅗ 모양 (4가지 회전)
    int tShapes[4][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, // ㅗ
        {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, // ㅏ
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}}, // ㅜ
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}  // ㅓ
    };
    
    for (int shape = 0; shape < 4; shape++) {
        int sum = 0;
        bool valid = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + tShapes[shape][i][0];
            int ny = y + tShapes[shape][i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                valid = false;
                break;
            }
            sum += board[nx][ny];
        }
        
        if (valid) {
            maxSum = max(maxSum, sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // DFS로 연결된 4개 블록 탐색 (I, O, L, J, S, Z 모양)
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            
            // ㅗ 모양 직접 확인
            checkTShape(i, j);
        }
    }
    
    cout << maxSum << endl;
    return 0;
}