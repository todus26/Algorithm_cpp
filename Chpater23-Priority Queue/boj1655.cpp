// 1655번 - 가운데를 말해요
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }
        
        cout << maxHeap.top() << '\n';
    }
    
    return 0;
}