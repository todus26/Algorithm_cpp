// 14889번 - 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> S;
vector<bool> visited;
int min_diff = 1e9;

void dfs(int idx, int count) {
    if (count == N / 2) {
        int start_team = 0, link_team = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visited[i] && visited[j]) {
                    start_team += S[i][j];
                }
                if (!visited[i] && !visited[j]) {
                    link_team += S[i][j];
                }
            }
        }
        min_diff = min(min_diff, abs(start_team - link_team));
        return;
    }
    for (int i = idx; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;
    S.resize(N, vector<int>(N));
    visited.resize(N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }
    dfs(0, 0);
    cout << min_diff << endl;
    return 0;
}
