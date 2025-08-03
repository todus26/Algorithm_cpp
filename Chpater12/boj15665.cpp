// 15665 N과 M (11)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, int m, vector<int>& arr, vector<int>& result) {
    if (result.size() == m) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    
    int prev = -1; // 이전에 사용한 값을 기억 (중복 방지)
    for (int i = 0; i < n; i++) {
        // 같은 깊이에서 이미 사용한 값이면 건너뛰기
        if (prev == arr[i]) continue;
        
        result.push_back(arr[i]);
        dfs(n, m, arr, result);
        result.pop_back();
        
        prev = arr[i];
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
    dfs(n, m, arr, result);
    
    return 0;
}