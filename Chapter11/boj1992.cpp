// 1992번 - 쿼드트리
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void compress(const vector<vector<int>>& matrix, int x, int y, int size) {
    if (size == 1) {
        cout << matrix[x][y];
        return;
    }

    int firstValue = matrix[x][y];
    bool isUniform = true;

    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (matrix[i][j] != firstValue) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    if (isUniform) {
        cout << firstValue;
    } else {
        cout << '(';
        int halfSize = size / 2;
        // 분할 순서: 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
        compress(matrix, x, y, halfSize);                    // 왼쪽 위
        compress(matrix, x, y + halfSize, halfSize);         // 오른쪽 위
        compress(matrix, x + halfSize, y, halfSize);         // 왼쪽 아래
        compress(matrix, x + halfSize, y + halfSize, halfSize); // 오른쪽 아래
        cout << ')';
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    
    // 문자열로 입력받아서 각 문자를 숫자로 변환
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = line[j] - '0';  // 문자를 숫자로 변환
        }
    }

    compress(matrix, 0, 0, N);
    cout << endl;

    return 0;
}