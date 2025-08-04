// 15664 - N과 M (10)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr, ans;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int prev = -1;  // 이전에 선택한 값을 기록
    for (int i = idx; i < N; i++) {
        if (arr[i] != prev) {  // 이전 값과 다른 경우만 선택
            ans.push_back(arr[i]);
            prev = arr[i];  // 현재 선택한 값을 기록
            dfs(i + 1, cnt + 1);  // 다음 인덱스부터 탐색 (조합)
            ans.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0);
    return 0;
}