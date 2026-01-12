#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100001;
int visited[MAX];  // 방문 시간 기록 (-1: 미방문)

int bfs(int n, int k) {
    // 시작점과 도착점이 같은 경우
    if (n == k) return 0;
    
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 세 가지 이동 방법
        int next[3] = {current - 1, current + 1, current * 2};
        
        for (int i = 0; i < 3; i++) {
            int nx = next[i];
            
            // 범위 체크 및 방문 체크
            if (nx >= 0 && nx < MAX && visited[nx] == -1) {
                visited[nx] = visited[current] + 1;
                
                // 동생을 찾았다면 시간 반환
                if (nx == k) {
                    return visited[nx];
                }
                
                q.push(nx);
            }
        }
    }
    
    return -1;  // 도달 불가능 (문제 조건상 발생하지 않음)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    // visited 배열 초기화
    memset(visited, -1, sizeof(visited));
    
    cout << bfs(n, k) << '\n';
    
    return 0;
}