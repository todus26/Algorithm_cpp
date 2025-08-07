// 7795번 - 먹을 것인가 먹힐 것인가
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<int> A(N);
        vector<int> B(M);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }
        
        // B 배열을 정렬
        sort(B.begin(), B.end());
        
        int count = 0;
        
        // 각 A의 원소에 대해 B에서 작은 원소의 개수를 찾기
        for (int i = 0; i < N; i++) {
            // lower_bound: A[i]보다 작은 B의 원소 개수를 찾기
            int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            count += idx;
        }
        
        cout << count << '\n';
    }
    
    return 0;
}