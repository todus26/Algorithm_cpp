//2110번 - 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canInstall(vector<int>& houses, int n, int c, int distance) {
    int count = 1;
    int lastPosition = houses[0];
    
    for (int i = 1; i < n; i++) {
        if (houses[i] - lastPosition >= distance) {
            count++;
            lastPosition = houses[i];
            if (count >= c) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    
    sort(houses.begin(), houses.end());
    
    int left = 1;
    int right = houses[n-1] - houses[0];
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canInstall(houses, n, c, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}