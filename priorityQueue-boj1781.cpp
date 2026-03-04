// 1781번 - 컵라면
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i].first >> problems[i].second;
    }
    
    sort(problems.begin(), problems.end());
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < n; i++) {
        int deadline = problems[i].first;
        int reward = problems[i].second;
        
        minHeap.push(reward);
        
        if (minHeap.size() > deadline) {
            minHeap.pop();
        }
    }
    
    long long total = 0;
    while (!minHeap.empty()) {
        total += minHeap.top();
        minHeap.pop();
    }
    
    cout << total << '\n';
    
    return 0;
}