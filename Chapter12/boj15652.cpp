// 15652 - N과 M (4)
#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, int depth, vector<int>& result, int start) {
    if (depth == m) {
        for (int i = 0; i < m; ++i) {
            cout << result[i] << (i < m - 1 ? " " : "\n");
        }
        return;
    }
    for (int i = start; i <= n; ++i) {
        result.push_back(i);
        dfs(n, m, depth + 1, result, i);
        result.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> result;
    dfs(n, m, 0, result, 1);
    return 0;
}
