// 11055번 - 가장 큰 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
