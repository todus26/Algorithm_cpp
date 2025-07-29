#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> dist(100001, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[N] = 0;
    pq.push({0, N});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (curr == K) {
            cout << d << "\n";
            return 0;
        }
        
        if (d > dist[curr]) continue;
        
        // 순간이동
        if (curr * 2 <= 100000 && dist[curr * 2] > d) {
            dist[curr * 2] = d;
            pq.push({d, curr * 2});
        }
        
        // 걷기
        if (curr + 1 <= 100000 && dist[curr + 1] > d + 1) {
            dist[curr + 1] = d + 1;
            pq.push({d + 1, curr + 1});
        }
        if (curr - 1 >= 0 && dist[curr - 1] > d + 1) {
            dist[curr - 1] = d + 1;
            pq.push({d + 1, curr - 1});
        }
    }
    
    return 0;
}