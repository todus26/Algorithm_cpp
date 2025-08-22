//13144번 - List of Unique Numbers
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long answer = 0;
    int left = 0;
    unordered_set<int> window;
    
    for (int right = 0; right < n; right++) {
        while (window.find(arr[right]) != window.end()) {
            window.erase(arr[left]);
            left++;
        }
        
        window.insert(arr[right]);
        answer += (right - left + 1);
    }
    
    cout << answer << '\n';
    
    return 0;
}