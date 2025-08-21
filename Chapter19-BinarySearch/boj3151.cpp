//3151번 - 합이 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    long long answer = 0;
    
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        
        while (left < right) {
            int sum = v[i] + v[left] + v[right];
            
            if (sum == 0) {
                if (v[left] == v[right]) {
                    int cnt = right - left + 1;
                    answer += (long long)cnt * (cnt - 1) / 2;
                    break;
                } else {
                    int leftCnt = 1, rightCnt = 1;
                    
                    while (left + leftCnt < right && v[left] == v[left + leftCnt]) {
                        leftCnt++;
                    }
                    while (right - rightCnt > left && v[right] == v[right - rightCnt]) {
                        rightCnt++;
                    }
                    
                    answer += (long long)leftCnt * rightCnt;
                    left += leftCnt;
                    right -= rightCnt;
                }
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}