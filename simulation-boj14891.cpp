// 14891번 - 톱니바퀴
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<vector<int>> gears(4, vector<int>(8));
    
    // 입력: 각 톱니바퀴를 문자열로 받아서 처리
    for (int i = 0; i < 4; ++i) {
        string gear;
        cin >> gear;
        for (int j = 0; j < 8; ++j) {
            gears[i][j] = gear[j] - '0'; // 문자를 숫자로 변환
        }
    }
    
    int k;
    cin >> k;

    while (k--) {
        int gearNum, direction;
        cin >> gearNum >> direction;
        --gearNum; // 0-indexed로 변환
        
        vector<int> rotate(4, 0); // 각 톱니바퀴의 회전 방향 저장
        rotate[gearNum] = direction;
        
        // 왼쪽 톱니바퀴 회전
        for (int i = gearNum; i > 0; --i) {
            if (gears[i][6] != gears[i - 1][2]) { // 맞닿는 극이 다르면 회전
                rotate[i - 1] = -rotate[i]; // 반대 방향으로 회전
            } else {
                break; // 회전하지 않으면 더 이상 전파되지 않음
            }
        }
        
        // 오른쪽 톱니바퀴 회전
        for (int i = gearNum; i < 3; ++i) {
            if (gears[i][2] != gears[i + 1][6]) { // 맞닿는 극이 다르면 회전
                rotate[i + 1] = -rotate[i]; // 반대 방향으로 회전
            } else {
                break; // 회전하지 않으면 더 이상 전파되지 않음
            }
        }
        
        // 톱니바퀴 회전 적용
        for (int i = 0; i < 4; ++i) {
            if (rotate[i] == 1) { // 시계 방향 회전
                int temp = gears[i][7];
                for (int j = 7; j > 0; --j) {
                    gears[i][j] = gears[i][j - 1];
                }
                gears[i][0] = temp;
            }
            else if (rotate[i] == -1) { // 반시계 방향 회전
                int temp = gears[i][0];
                for (int j = 0; j < 7; ++j) {
                    gears[i][j] = gears[i][j + 1];
                }
                gears[i][7] = temp;
            }
        }
    }
    
    // 결과 출력
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (gears[i][0] == 1) { // 12시 방향이 S극(1)이면 점수 추가
            score += (1 << i); // 2^i 점수 추가
        }
    }
    cout << score << endl;
    return 0;
}