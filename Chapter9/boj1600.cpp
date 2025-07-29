#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>  
using namespace std;

int K, W, H;
int board[201][201];
bool visited[201][201][31];
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
int dx2[4] = { -1, 0, 1, 0 };
int dy2[4] = { 0, -1, 0, 1 };

int bfs() {
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [x, y, k, d] = q.front();
        q.pop();

        if (x == W - 1 && y == H - 1) {
            return d;
        }

        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < W && ny >= 0 && ny < H && 
                    board[ny][nx] == 0 && !visited[ny][nx][k + 1]) {
                    visited[ny][nx][k + 1] = true;
                    q.push({nx, ny, k + 1, d + 1});
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx2[i];
            int ny = y + dy2[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H && 
                board[ny][nx] == 0 && !visited[ny][nx][k]) {
                visited[ny][nx][k] = true;
                q.push({nx, ny, k, d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> K >> W >> H;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    cout << bfs() << endl;
    
    return 0;
}