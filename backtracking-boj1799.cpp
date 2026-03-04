#include <bits/stdc++.h>
using namespace std;

int N, board[10][10], ans[2];
bool diag1[20], diag2[20];
vector<pair<int,int>> cells[2];

void solve(int idx, int color, int cnt) {
    if (idx == (int)cells[color].size()) {
        ans[color] = max(ans[color], cnt);
        return;
    }
    auto [r, c] = cells[color][idx];
    // 놓지 않는 경우
    solve(idx + 1, color, cnt);
    // 놓는 경우
    int d1 = r + c, d2 = r - c + N - 1;
    if (!diag1[d1] && !diag2[d2]) {
        diag1[d1] = diag2[d2] = true;
        solve(idx + 1, color, cnt + 1);
        diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j])
                cells[(i + j) % 2].push_back({i, j});
        }
    solve(0, 0, 0);
    solve(0, 1, 0);
    cout << ans[0] + ans[1] << "\n";
}