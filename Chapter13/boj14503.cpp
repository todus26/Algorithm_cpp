// 14503번 - 로봇 청소기
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int r, c, d;
vector<vector<int>> room;
int cleanedCount = 0;

// 방향 벡터 (북, 동, 남, 서)
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// 왼쪽으로 회전
int turnLeft(int direction) {
    return (direction + 3) % 4;
}

// 청소 함수
void cleanRoom() {
    while (true) {
        // 1. 현재 위치가 청소되지 않은 경우 청소
        if (room[r][c] == 0) {
            room[r][c] = 2; // 청소됨을 표시
            cleanedCount++;
        }
        
        // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색
        bool found = false;
        
        for (int i = 0; i < 4; i++) {
            d = turnLeft(d); // 왼쪽으로 회전
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            // 청소되지 않은 빈 칸이 있는 경우
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && room[nr][nc] == 0) {
                r = nr;
                c = nc;
                found = true;
                break;
            }
        }
        
        if (found) {
            continue; // 이동했으므로 다시 청소 시작
        }
        
        // 3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        // 바라보는 방향을 유지한 채로 한 칸 후진
        int backDir = (d + 2) % 4; // 현재 방향의 반대 방향
        int br = r + dr[backDir];
        int bc = c + dc[backDir];
        
        // 후진할 수 있는 경우
        if (br >= 0 && br < n && bc >= 0 && bc < m && room[br][bc] != 1) {
            r = br;
            c = bc;
        } else {
            // 후진할 수 없는 경우 작동 정지
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 첫째 줄: 방의 크기 N, M
    cin >> n >> m;
    
    // 둘째 줄: 로봇 청소기의 좌표 (r, c)와 방향 d
    cin >> r >> c >> d;
    
    // 셋째 줄부터: 방의 상태
    room.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    
    cleanRoom();
    
    cout << cleanedCount << endl;
    
    return 0;
}