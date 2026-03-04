#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int laptop[41][41];

vector<vector<int>> rotate(vector<vector<int>>& s) {
    int r = s.size(), c = s[0].size();
    vector<vector<int>> res(c, vector<int>(r));
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            res[j][r-1-i] = s[i][j];
    return res;
}

bool tryPaste(vector<vector<int>>& s) {
    int sr = s.size(), sc = s[0].size();
    for (int i=0;i<=N-sr;i++) {
        for (int j=0;j<=M-sc;j++) {
            // (i,j)에 붙일 수 있는지 확인
            bool ok = true;
            for (int x=0;x<sr&&ok;x++)
                for (int y=0;y<sc&&ok;y++)
                    if (s[x][y] && laptop[i+x][j+y]) ok = false;
            if (ok) {
                for (int x=0;x<sr;x++)
                    for (int y=0;y<sc;y++)
                        if (s[x][y]) laptop[i+x][j+y] = 1;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    while (K--) {
        int r, c; cin >> r >> c;
        vector<vector<int>> s(r, vector<int>(c));
        for (auto& row : s) for (auto& v : row) cin >> v;
        for (int rot=0;rot<4;rot++) {
            if (tryPaste(s)) break;
            s = rotate(s);
        }
    }
    int ans = 0;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            ans += laptop[i][j];
    cout << ans << "\n";
}