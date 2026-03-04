#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int visited[1000001];

// 두 수의 안전 거리 계산 (서로 다른 비트 개수)
int safeDist(int a, int b) {
    int xorVal = a ^ b;
    int count = 0;
    while (xorVal > 0) {
        count += xorVal & 1;
        xorVal >>= 1;
    }
    return count;
}

int bfs(queue<int>& q) {
    int maxDist = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 각 비트를 뒤집어서 새로운 비밀번호 생성
        for (int bit = 0; (1 << bit) <= N; bit++) {
            int next = current ^ (1 << bit);
            
            if (next > N) continue;
            if (visited[next] != -1) continue;
            
            visited[next] = visited[current] + 1;
            maxDist = max(maxDist, visited[next]);
            q.push(next);
        }
    }
    
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    memset(visited, -1, sizeof(visited));
    
    queue<int> q;
    
    for (int i = 0; i < M; i++) {
        int pwd;
        cin >> pwd;
        if (visited[pwd] == -1) {
            visited[pwd] = 0;
            q.push(pwd);
        }
    }
    
    int result = bfs(q);
    cout << result << "\n";
    
    return 0;
}