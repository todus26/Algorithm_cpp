// 1003번 - 피보나치 함수
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    // dp[i][0] = fibonacci(i)를 호출했을 때 0이 출력되는 횟수
    // dp[i][1] = fibonacci(i)를 호출했을 때 1이 출력되는 횟수
    int dp[41][2];
    
    // 초기값 설정
    dp[0][0] = 1;  // fibonacci(0)은 0을 1번 출력
    dp[0][1] = 0;  // fibonacci(0)은 1을 0번 출력
    dp[1][0] = 0;  // fibonacci(1)은 0을 0번 출력
    dp[1][1] = 1;  // fibonacci(1)은 1을 1번 출력
    
    // DP 테이블 채우기
    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    
    // 각 테스트 케이스 처리
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << '\n';
    }
    
    return 0;
}