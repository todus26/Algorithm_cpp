#include <iostream>
using namespace std;

pair<int, int> hilbert(int n, int m) {
    if (n == 2) {
        if (m == 1) return {1, 1};
        if (m == 2) return {1, 2};
        if (m == 3) return {2, 2};
        if (m == 4) return {2, 1};
    }
    
    int half = n / 2;
    int area = half * half;
    
    if (m <= area) {
        // 1사분면 (왼쪽 아래)
        auto rv = hilbert(half, m);
        return {rv.second, rv.first};
    }
    else if (m <= 2 * area) {
        // 2사분면 (왼쪽 위)
        auto rv = hilbert(half, m - area);
        return {rv.first, half + rv.second};
    }
    else if (m <= 3 * area) {
        // 3사분면 (오른쪽 위)
        auto rv = hilbert(half, m - 2 * area);
        return {half + rv.first, half + rv.second};
    }
    else {
        // 4사분면 (오른쪽 아래)
        auto rv = hilbert(half, m - 3 * area);
        return {2 * half - rv.second + 1, half - rv.first + 1};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    auto ans = hilbert(n, m);
    cout << ans.first << " " << ans.second << "\n";
    
    return 0;
}