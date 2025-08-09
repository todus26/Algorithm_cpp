// 15486번 - 퇴사 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n + 1), p(n + 1), dp(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }
    for (int i = n; i >= 1; --i) {
        if (i + t[i] <= n + 1) dp[i] = max(p[i] + dp[i + t[i]], dp[i + 1]);
        else dp[i] = dp[i + 1];
    }
    cout << dp[1];
    return 0;
}
