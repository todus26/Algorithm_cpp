// 15650 - N과 M (2)
#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, int start, vector<int>& result) {
    if (result.size() == m) {
        for (int i = 0; i < m; ++i) {
            cout << result[i] << (i < m - 1 ? " " : "\n");
        }
        return;
    }
    for (int i = start; i <= n; ++i) {
        result.push_back(i);
        dfs(n, m, i + 1, result);
        result.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> result;
    dfs(n, m, 1, result);
    return 0;
}