// 1912번 - 연속합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(n);
    dp[0] = arr[0];
    int answer = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}
