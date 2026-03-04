// 11559 번 - Puyo Puyo
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<char>> board;
vector<vector<bool>> visited;

void dfs(int x, int y, char color, vector<pair<int, int>>& puyos) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || board[x][y] != color) {
        return;
    }
    visited[x][y] = true;
    puyos.push_back({x, y});

    // 상하좌우 탐색
    dfs(x - 1, y, color, puyos);
    dfs(x + 1, y, color, puyos);
    dfs(x, y - 1, color, puyos);
    dfs(x, y + 1, color, puyos);
}

int main() {
    n = 12; // 고정값
    m = 6;  // 고정값
    board.resize(n, vector<char>(m));
    
    // 입력을 문자열로 받아서 처리
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < m; ++j) {
            board[i][j] = line[j];
        }
    }

    int chainCount = 0; // 연쇄 횟수
    bool popped;
    do {
        popped = false;
        visited.assign(n, vector<bool>(m, false));
        vector<vector<pair<int, int>>> clusters;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && board[i][j] != '.') { // '.'는 빈 칸      
                    vector<pair<int, int>> puyos;
                    dfs(i, j, board[i][j], puyos);
                    if (puyos.size() >= 4) {
                        clusters.push_back(puyos);
                        popped = true;
                    }
                }
            }
        }

        // 터진 푸요들을 제거
        if (popped) {
            chainCount++; // 연쇄 횟수 증가
            for (const auto& puyos : clusters) {
                for (const auto& p : puyos) {
                    board[p.first][p.second] = '.'; // 빈 칸으로 설정
                }
            }
        }
        
        // 중력 효과 적용
        for (int j = 0; j < m; ++j) {
            int emptyRow = n - 1; // 빈 칸의 위치
            for (int i = n - 1; i >= 0; --i) {  
                if (board[i][j] != '.') {
                    if (i != emptyRow) {
                        board[emptyRow][j] = board[i][j];   
                        board[i][j] = '.'; // 원래 위치는 빈 칸으로
                    }
                    emptyRow--; // 빈 칸 위치를 위로 이동
                }
            }
        }
    } while (popped);

    cout << chainCount << endl;
    return 0;
}