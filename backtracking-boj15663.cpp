// 15663 - N과 M (9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr, ans;
vector<bool> visited;

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int prev = -1;  // 이전에 선택한 값을 기록
    for (int i = 0; i < N; i++) {
        if (!visited[i] && arr[i] != prev) {  // 방문하지 않았고, 이전 값과 다른 경우
            visited[i] = true;
            ans.push_back(arr[i]);
            prev = arr[i];  // 현재 선택한 값을 기록
            dfs(cnt + 1);
            ans.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    arr.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dfs(0);
    return 0;
}