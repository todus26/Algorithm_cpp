#include <bits/stdc++.h>
using namespace std;

int N, M, board[8][8], ans = 64;
vector<pair<int,int>> cctvs;

// 방향: 0=우, 1=하, 2=좌, 3=상
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

void watch(int map[8][8], int r, int c, int dir) {
    while (true) {
        r += dr[dir]; c += dc[dir];
        if (r<0||r>=N||c<0||c>=M||map[r][c]==6) break;
        if (map[r][c]==0) map[r][c]=-1;
    }
}

// CCTV 종류별 방향 목록 (회전 경우의 수)
vector<vector<vector<int>>> dirs = {
    {{0},{1},{2},{3}},           // 1번
    {{0,2},{1,3}},               // 2번
    {{0,1},{1,2},{2,3},{3,0}},   // 3번
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}}, // 4번
    {{0,1,2,3}}                  // 5번
};

void dfs(int idx, int map[8][8]) {
    if (idx == (int)cctvs.size()) {
        int cnt = 0;
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                if (map[i][j]==0) cnt++;
        ans = min(ans, cnt);
        return;
    }
    auto [r,c] = cctvs[idx];
    int type = board[r][c] - 1;
    for (auto& ds : dirs[type]) {
        int tmp[8][8];
        memcpy(tmp, map, sizeof(tmp));
        for (int d : ds) watch(tmp, r, c, d);
        dfs(idx+1, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
            if (board[i][j]>=1 && board[i][j]<=5)
                cctvs.push_back({i,j});
        }
    dfs(0, board);
    cout << ans << "\n";
}