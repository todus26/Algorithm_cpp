// 1932번 - 정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 삼각형 입력받기
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    
    // DP 배열 (각 위치까지의 최대 합)
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(i + 1);
    }
    
    // 초기값: 맨 위의 값
    dp[0][0] = triangle[0][0];
    
    // DP 진행: 위에서부터 아래로
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // 왼쪽 끝
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            // 오른쪽 끝
            else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            // 중간
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    // 마지막 줄에서 최댓값 찾기
    int answer = 0;
    for (int j = 0; j < n; j++) {
        answer = max(answer, dp[n-1][j]);
    }
    
    cout << answer << endl;
    
    return 0;
}