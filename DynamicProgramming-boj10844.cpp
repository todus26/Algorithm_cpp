// 10844번 - 쉬운 계단 수
#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int N;
    cin >> N;
    
    // dp[i][j] = i자리 계단 수 중 마지막 숫자가 j인 경우의 수
    long long dp[101][10] = {0};
    
    // 1자리 계단 수 초기화 (1~9로 시작, 0으로는 시작할 수 없음)
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    // 2자리부터 N자리까지 계산
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            // j로 끝나는 i자리 계단 수를 만들기
            // 이전 자리 수가 j-1 또는 j+1이어야 함
            
            if (j > 0) {
                // 이전 숫자가 j-1인 경우
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            if (j < 9) {
                // 이전 숫자가 j+1인 경우
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    
    // N자리 계단 수의 총 개수 계산
    long long answer = 0;
    for (int j = 0; j <= 9; j++) {
        answer = (answer + dp[N][j]) % MOD;
    }
    
    cout << answer << endl;
    
    return 0;
}