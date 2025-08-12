// 11501번 - 주식
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> prices(N);
        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }
        
        long long profit = 0;
        int maxPrice = 0;
        
        // 뒤에서부터 탐색
        for (int i = N - 1; i >= 0; i--) {
            if (prices[i] > maxPrice) {
                // 현재 가격이 최고가보다 높으면 최고가 갱신
                maxPrice = prices[i];
            } else {
                // 현재 가격이 최고가보다 낮으면 차익 실현
                profit += (maxPrice - prices[i]);
            }
        }
        
        cout << profit << '\n';
    }
    
    return 0;
}