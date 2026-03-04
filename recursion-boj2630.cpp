// 2630 번 - 색종이 만들기
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> paper;
int white = 0, blue = 0;

void countColor(int x, int y, int size) {
    int color = paper[x][y];
    bool isUniform = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    if (isUniform) {
        if (color == 0) white++;
        else blue++;
    } else {
        int newSize = size / 2;
        countColor(x, y, newSize);
        countColor(x, y + newSize, newSize);
        countColor(x + newSize, y, newSize);
        countColor(x + newSize, y + newSize, newSize);
    }
}

int main() {
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    countColor(0, 0, N);

    cout << white << endl;
    cout << blue << endl;

    return 0;
}