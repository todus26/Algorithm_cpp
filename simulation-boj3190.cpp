// 3190번 - 뱀
#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int n, k, l;
vector<vector<int>> board;
deque<pair<int, int>> snake;
map<int, char> turns; // 시간별 방향 전환 정보

int direction = 0; // 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위

// 방향 벡터 (오른쪽, 아래, 왼쪽, 위)
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

// 방향 전환
void changeDirection(char turn) {
    if (turn == 'L') {
        direction = (direction + 3) % 4; // 왼쪽으로 회전 (반시계방향)
    } else if (turn == 'D') {
        direction = (direction + 1) % 4; // 오른쪽으로 회전 (시계방향)
    }
}

// 게임 진행
int playGame() {
    int time = 0;
    snake.push_back({0, 0}); // 뱀의 초기 위치 (0, 0)
    
    while (true) {
        time++;
        
        // 현재 머리 위치
        pair<int, int> head = snake.front();
        
        // 다음 머리 위치 계산
        int nextR = head.first + dr[direction];
        int nextC = head.second + dc[direction];
        
        // 벽에 부딪히는지 확인
        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) {
            return time;
        }
        
        // 자기 몸에 부딪히는지 확인
        for (auto& body : snake) {
            if (body.first == nextR && body.second == nextC) {
                return time;
            }
        }
        
        // 뱀의 머리를 새 위치로 이동
        snake.push_front({nextR, nextC});
        
        // 사과가 있는지 확인
        bool ateApple = false;
        if (board[nextR][nextC] == 1) { // 사과가 있음
            board[nextR][nextC] = 0; // 사과 제거
            ateApple = true;
        }
        
        // 사과를 먹지 않았으면 꼬리 제거
        if (!ateApple) {
            snake.pop_back();
        }
        
        // 방향 전환 확인
        if (turns.find(time) != turns.end()) {
            changeDirection(turns[time]);
        }
    }
    
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    board.resize(n, vector<int>(n, 0));
    
    // 사과 위치 입력
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과 위치 표시 (1-indexed to 0-indexed)
    }
    
    cin >> l;
    
    // 방향 전환 정보 입력
    for (int i = 0; i < l; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        turns[time] = dir;
    }
    
    int result = playGame();
    cout << result << endl;
    
    return 0;
}