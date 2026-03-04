// 15654 - N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, int m, int depth, vector<int>& result, vector<int>& nums, vector<bool>& visited) {
    if (depth == m) {
        for (int i = 0; i < m; ++i) {
            cout << result[i] << (i < m - 1 ? " " : "\n");
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            result.push_back(nums[i]);
            dfs(n, m, depth + 1, result, nums, visited);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<int> result;
    vector<bool> visited(n, false);
    dfs(n, m, 0, result, nums, visited);
    return 0;
}
