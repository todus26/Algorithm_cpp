//7453번 - 합이 0인 네 정수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    vector<long long> AB, CD;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }
    
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    
    long long answer = 0;
    int left = 0, right = CD.size() - 1;
    
    while (left < AB.size() && right >= 0) {
        long long sum = AB[left] + CD[right];
        
        if (sum == 0) {
            long long leftCnt = 1, rightCnt = 1;
            
            while (left + leftCnt < AB.size() && AB[left] == AB[left + leftCnt]) {
                leftCnt++;
            }
            while (right - rightCnt >= 0 && CD[right] == CD[right - rightCnt]) {
                rightCnt++;
            }
            
            answer += leftCnt * rightCnt;
            left += leftCnt;
            right -= rightCnt;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}