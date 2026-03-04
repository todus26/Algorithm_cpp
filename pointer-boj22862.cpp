//22862번 - 가장 긴 짝수 연속한 부분 수열 (large)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int left = 0, right = 0;
    int oddCount = 0;
    int maxLength = 0;
    
    while (right < n) {
        if (arr[right] % 2 == 1) {
            oddCount++;
        }
        
        while (oddCount > k) {
            if (arr[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }
        
        maxLength = max(maxLength, right - left + 1 - oddCount);
        right++;
    }
    
    cout << maxLength << '\n';
    
    return 0;
}