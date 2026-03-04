// 15651 - N과 M (3)
#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, int depth, vector<int>& result) {    
    if (depth == m) {
        for (int i = 0; i < m; ++i) {
            cout << result[i] << (i < m - 1 ? " " : "\n");
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        result.push_back(i);
        dfs(n, m, depth + 1, result);
        result.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> result;
    dfs(n, m, 0, result);
    return 0;
}