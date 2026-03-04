#include <iostream>
using namespace std;

int N, S;
int arr[20];
int cnt = 0;

void solve(int idx, int sum) {
    if(idx == N) {
        if(sum == S) cnt++;
        return;
    }
    
    // 현재 원소를 포함하는 경우
    solve(idx + 1, sum + arr[idx]);
    
    // 현재 원소를 포함하지 않는 경우
    solve(idx + 1, sum);
}

int main() {
    cin >> N >> S;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    solve(0, 0);
    
    // 공집합 제외
    if(S == 0) cnt--;
    
    cout << cnt;
    
    return 0;
}