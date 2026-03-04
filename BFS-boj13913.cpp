#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int visited[100001];
int parent[100001];

void bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    parent[N] = -1;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == K) {
            return;
        }
        
        // 세 가지 이동 방법
        int next[3] = {current - 1, current + 1, current * 2};
        
        for (int i = 0; i < 3; i++) {
            int nx = next[i];
            
            if (nx < 0 || nx > 100000) continue;
            if (visited[nx] != -1) continue;
            
            visited[nx] = visited[current] + 1;
            parent[nx] = current;
            q.push(nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    fill(visited, visited + 100001, -1);
    
    if (N == K) {
        cout << "0\n";
        cout << N << "\n";
        return 0;
    }
    
    bfs();
    
    cout << visited[K] << "\n";
    
    // 경로 추적
    vector<int> path;
    int current = K;
    
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    
    // 역순으로 출력
    reverse(path.begin(), path.end());
    
    for (int pos : path) {
        cout << pos << " ";
    }
    cout << "\n";
    
    return 0;
}