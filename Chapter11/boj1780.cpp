// 1780번 - 종이의 개수
#include <iostream>
#include <vector>
using namespace std;

int paper[2200][2200];
int count[3] = {0, 0, 0}; // -1, 0, 1

void countPapers(int x, int y, int size) {
    int first = paper[y][x];
    bool isUniform = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (paper[i][j] != first) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    if (isUniform) {
        count[first + 1]++;
    } else {
        int newSize = size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                countPapers(x + j * newSize, y + i * newSize, newSize);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    countPapers(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << count[i] << endl;
    }

    return 0;
}