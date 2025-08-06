// 15685번 - 드래곤 커브
#include <iostream>
#include <vector>
using namespace std;

int N;
bool grid[101][101];

// 방향: 0=오른쪽(→), 1=위(↑), 2=왼쪽(←), 3=아래(↓)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void makeDragonCurve(int x, int y, int d, int g) {
    vector<int> directions;
    
    // 시작점 표시
    grid[x][y] = true;
    
    // 0세대: 시작 방향으로 한 칸 이동
    directions.push_back(d);
    x += dx[d];
    y += dy[d];
    grid[x][y] = true;
    
    // 1세대부터 g세대까지 생성
    for (int gen = 1; gen <= g; gen++) {
        int size = directions.size();
        
        // 이전 세대의 방향들을 역순으로 읽으면서
        // 각 방향을 90도 시계방향 회전(+1)하여 추가
        for (int i = size - 1; i >= 0; i--) {
            int newDir = (directions[i] + 1) % 4;
            x += dx[newDir];
            y += dy[newDir];
            
            // 격자 범위 체크
            if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
                grid[x][y] = true;
            }
            
            directions.push_back(newDir);
        }
    }
}

int countSquares() {
    int count = 0;
    
    // 1x1 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인지 확인
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i + 1][j] && 
                grid[i][j + 1] && grid[i + 1][j + 1]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        makeDragonCurve(x, y, d, g);
    }
    
    cout << countSquares() << endl;
    
    return 0;
}