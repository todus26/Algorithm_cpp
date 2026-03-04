// 6603 - 로또
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int k, vector<int>& arr, vector<int>& result, int start) {
    if (result.size() == 6) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++) {
        result.push_back(arr[i]);
        dfs(k, arr, result, i + 1);
        result.pop_back();
    }
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        vector<int> arr(k);
        vector<int> result;
        
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        
        // 입력이 이미 오름차순으로 주어지므로 정렬 불필요
        dfs(k, arr, result, 0);
        cout << "\n";
    }
    return 0;
}