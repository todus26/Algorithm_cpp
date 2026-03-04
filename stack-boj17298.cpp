// 17298번 - 오큰수
#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    stack<pair<int, int>> S; // (값, 인덱스)
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans[n]; // 결과 배열 초기화
    
    for (int i = 0; i < n; i++) {
        while (!S.empty() && S.top().X < arr[i]) {
            ans[S.top().Y] = arr[i]; // 현재 값이 스택의 top보다 크면 오큰수 설정
            S.pop();
        }
        S.push({arr[i], i}); // 현재 값과 인덱스를 스택에 추가
    }
    
    while (!S.empty()) {
        ans[S.top().Y] = -1; // 오큰수가 없는 경우 -1 설정
        S.pop();
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; // 결과 출력
    }
    
    return 0;
}