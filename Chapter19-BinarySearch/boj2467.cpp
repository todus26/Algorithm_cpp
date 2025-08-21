//2467번 - 용액
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
    
    vector<int> liquid(N);
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    
    int left = 0, right = N - 1;
    int minSum = INT_MAX;
    int answerLeft = 0, answerRight = 0;
    
    while (left < right) {
        int sum = liquid[left] + liquid[right];
        
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            answerLeft = liquid[left];
            answerRight = liquid[right];
        }
        
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << answerLeft << " " << answerRight << '\n';
    
    return 0;
}