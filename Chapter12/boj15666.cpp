// 15666 - N과 M (12)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, int m, vector<int>& arr, vector<int>& result, int start) {
    if (result.size() == m) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = start; i < n; i++) {
        // 같은 깊이에서 중복된 값 건너뛰기
        if (i > start && arr[i] == arr[i - 1]) continue;
        
        result.push_back(arr[i]);
        // 중복을 허용하므로 i부터 시작 (i+1이 아님)
        dfs(n, m, arr, result, i);
        result.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    dfs(n, m, arr, result, 0);
    
    return 0;
}