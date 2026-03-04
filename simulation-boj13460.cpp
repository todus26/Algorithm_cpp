// 13460번 - 구슬 탈출 2
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct State {
    int rx, ry, bx, by, moves;
};

int n, m;
vector<string> board;
int hx, hy; // 구멍 위치

// 4방향 이동 (상, 하, 좌, 우)
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// 구슬을 굴려서 최종 위치와 구멍 도달 여부 반환
pair<pair<int, int>, bool> roll(int x, int y, int dir) {
    bool inHole = false;
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 벽에 부딪히면 멈춤
        if (board[ny][nx] == '#') {
            break;
        }
        
        x = nx;
        y = ny;
        
        // 구멍에 도달하면 표시하고 멈춤
        if (x == hx && y == hy) {
            inHole = true;
            break;
        }
    }
    return make_pair(make_pair(x, y), inHole);
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    map<vector<int>, bool> visited;
    
    q.push({rx, ry, bx, by, 0});
    vector<int> start_state = {rx, ry, bx, by};
    visited[start_state] = true;
    
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        // 10번을 초과하면 실패
        if (cur.moves >= 10) {
            continue;
        }
        
        // 4방향으로 기울이기
        for (int dir = 0; dir < 4; dir++) {
            // 빨간 구슬과 파란 구슬을 각각 굴림
            pair<pair<int, int>, bool> red_result = roll(cur.rx, cur.ry, dir);
            pair<pair<int, int>, bool> blue_result = roll(cur.bx, cur.by, dir);
            
            int nrx = red_result.first.first, nry = red_result.first.second;
            int nbx = blue_result.first.first, nby = blue_result.first.second;
            bool red_in_hole = red_result.second;
            bool blue_in_hole = blue_result.second;
            
            // 파란 구슬이 구멍에 들어가면 실패
            if (blue_in_hole) {
                continue;
            }
            
            // 빨간 구슬만 구멍에 들어가면 성공
            if (red_in_hole) {
                return cur.moves + 1;
            }
            
            // 두 구슬이 같은 위치에 있으면 조정
            if (nrx == nbx && nry == nby) {
                // 이동 방향에 따라 어느 구슬이 뒤에 있어야 하는지 결정
                if (dir == 0) { // 위쪽으로 이동: 원래 더 아래 있던 구슬이 뒤로
                    if (cur.ry > cur.by) nry++;
                    else nby++;
                } else if (dir == 1) { // 아래쪽으로 이동: 원래 더 위에 있던 구슬이 뒤로
                    if (cur.ry < cur.by) nry--;
                    else nby--;
                } else if (dir == 2) { // 왼쪽으로 이동: 원래 더 오른쪽에 있던 구슬이 뒤로
                    if (cur.rx > cur.bx) nrx++;
                    else nbx++;
                } else { // 오른쪽으로 이동: 원래 더 왼쪽에 있던 구슬이 뒤로
                    if (cur.rx < cur.bx) nrx--;
                    else nbx--;
                }
            }
            
            // 이미 방문한 상태면 건너뛰기
            vector<int> new_state = {nrx, nry, nbx, nby};
            if (visited.find(new_state) != visited.end()) {
                continue;
            }
            
            visited[new_state] = true;
            q.push({nrx, nry, nbx, nby, cur.moves + 1});
        }
    }
    
    return -1; // 실패
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    board.resize(n);
    
    int rx, ry, bx, by;
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                rx = j; ry = i;
                board[i][j] = '.'; // 빈 공간으로 변경
            } else if (board[i][j] == 'B') {
                bx = j; by = i;
                board[i][j] = '.'; // 빈 공간으로 변경
            } else if (board[i][j] == 'O') {
                hx = j; hy = i;
            }
        }
    }
    
    int result = bfs(rx, ry, bx, by);
    cout << result << endl;
    
    return 0;
}