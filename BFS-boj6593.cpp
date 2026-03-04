#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int L, R, C;
char building[30][30][30];
int visited[30][30][30];

// 6방향 이동 (상, 하, 동, 서, 남, 북)
int dl[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};

struct Point {
    int l, r, c;
};

int bfs(Point start, Point end) {
    queue<Point> q;
    q.push(start);
    visited[start.l][start.r][start.c] = 0;
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        if (cur.l == end.l && cur.r == end.r && cur.c == end.c) {
            return visited[cur.l][cur.r][cur.c];
        }
        
        for (int i = 0; i < 6; i++) {
            int nl = cur.l + dl[i];
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            
            if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (building[nl][nr][nc] == '#') continue;
            if (visited[nl][nr][nc] != -1) continue;
            
            visited[nl][nr][nc] = visited[cur.l][cur.r][cur.c] + 1;
            q.push({nl, nr, nc});
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        cin >> L >> R >> C;
        
        if (L == 0 && R == 0 && C == 0) break;
        
        memset(visited, -1, sizeof(visited));
        
        Point start, end;
        
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> building[i][j][k];
                    
                    if (building[i][j][k] == 'S') {
                        start = {i, j, k};
                    } else if (building[i][j][k] == 'E') {
                        end = {i, j, k};
                    }
                }
            }
        }
        
        int result = bfs(start, end);
        
        if (result == -1) {
            cout << "Trapped!\n";
        } else {
            cout << "Escaped in " << result << " minute(s).\n";
        }
    }
    
    return 0;
}