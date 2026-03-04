// 15657 - N과 M (8)
#include <iostream>
#include <vector>   
#include <algorithm>  // sort 함수를 위해 추가
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
    for (int i = idx; i < N; i++) {
        ans.push_back(arr[i]);
        dfs(i, cnt + 1);
        ans.pop_back();
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