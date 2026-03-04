// 15656 - N과 M (7)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

void dfs(int n, int m, int depth, vector<int>& result, vector<int>& nums) {
    if (depth == m) {
        for (int i = 0; i < m; ++i) {
            cout << result[i] << (i < m - 1 ? " " : "\n");
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        result.push_back(nums[i]);
        dfs(n, m, depth + 1, result, nums);
        result.pop_back();
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
    dfs(n, m, 0, result, nums);
    return 0;
}
