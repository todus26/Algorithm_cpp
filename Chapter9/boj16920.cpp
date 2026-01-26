#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, P;
int S[10];
char board[1000][1000];
queue<pair<int, int>> players[10];
int counts[10];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int player) {
    queue<pair<int, int>> nextQ;
    int moves = S[player];
    
    for (int move = 0; move < moves; move++) {
        if (players[player].empty()) break;
        
        int qSize = players[player].size();
        
        for (int i = 0; i < qSize; i++) {
            int x = players[player].front().first;
            int y = players[player].front().second;
            players[player].pop();
            
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (board[nx][ny] != '.') continue;
                
                board[nx][ny] = '0' + player;
                counts[player]++;
                nextQ.push({nx, ny});
            }
        }
        
        while (!nextQ.empty()) {
            players[player].push(nextQ.front());
            nextQ.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> P;
    
    for (int i = 1; i <= P; i++) {
        cin >> S[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                int player = board[i][j] - '0';
                players[player].push({i, j});
                counts[player]++;
            }
        }
    }
    
    bool expanded = true;
    
    while (expanded) {
        expanded = false;
        
        for (int p = 1; p <= P; p++) {
            int prevCount = counts[p];
            bfs(p);
            
            if (counts[p] > prevCount) {
                expanded = true;
            }
        }
    }
    
    for (int i = 1; i <= P; i++) {
        cout << counts[i] << " ";
    }
    cout << "\n";
    
    return 0;
}