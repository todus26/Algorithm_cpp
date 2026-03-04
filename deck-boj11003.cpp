// 11003번 - 최솟값 찾기
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    deque<pair<int, int>> dq;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }
        
        dq.push_back({i, num});

        if (dq.front().first <= i - m) {
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }

    return 0;
}