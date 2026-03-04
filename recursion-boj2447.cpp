// 2447 - 별찍기 10
#include <iostream>
#include <vector>
using namespace std;

void drawStars(vector<vector<char>>& grid, int x, int y, int size) {
    if (size == 1) {
        grid[x][y] = '*';
        return;
    }

    int newSize = size / 3;
    
    // 3x3 격자의 각 칸에 대해 처리
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // 가운데 칸(1,1)은 공백으로 두고, 나머지 8곳에 재귀적으로 패턴 그리기
            if (i == 1 && j == 1) {
                // 가운데 영역은 공백으로 둠 (이미 초기화할 때 공백으로 되어있음)
                continue;
            } else {
                // 나머지 8곳에 재귀적으로 패턴 그리기
                drawStars(grid, x + i * newSize, y + j * newSize, newSize);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N, ' '));
    drawStars(grid, 0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}