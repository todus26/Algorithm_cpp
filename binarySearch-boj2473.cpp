//2473번 - 세 용액
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<long long> liquid(N);
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    
    sort(liquid.begin(), liquid.end());
    
    long long minSum = LLONG_MAX;
    vector<long long> answer(3);
    
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        
        while (left < right) {
            long long sum = liquid[i] + liquid[left] + liquid[right];
            
            if (abs(sum) < abs(minSum)) {
                minSum = sum;
                answer[0] = liquid[i];
                answer[1] = liquid[left];
                answer[2] = liquid[right];
            }
            
            if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    cout << answer[0] << " " << answer[1] << " " << answer[2] << '\n';
    
    return 0;
}