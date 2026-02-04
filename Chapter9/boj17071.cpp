#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int visited[500001][2]; // [위치][홀수/짝수 시간]
int brother[500001]; // 동생의 시간별 위치

int bfs() {
    queue<pair<int, int>> q; // {위치, 시간}
    q.push({N, 0});
    visited[N][0] = 1;
    
    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        // 다음 시간의 동생 위치가 범위를 벗어나면 불가능
        if (time + 1 > 500000) continue;
        
        // 세 가지 이동 방법
        int next[3] = {pos - 1, pos + 1, pos * 2};
        
        for (int i = 0; i < 3; i++) {
            int npos = next[i];
            int ntime = time + 1;
            
            if (npos < 0 || npos > 500000) continue;
            
            // 이미 이 위치에 이 시간의 홀짝성으로 방문했으면 스킵
            if (visited[npos][ntime % 2]) continue;
            
            visited[npos][ntime % 2] = 1;
            q.push({npos, ntime});
        }
    }
    
    // 각 시간마다 동생의 위치에서 수빈이가 도달할 수 있는지 확인
    for (int t = 0; t <= 500000; t++) {
        if (brother[t] > 500000) break;
        
        // 시간 t에 동생 위치에 수빈이가 도달했는지 확인
        if (visited[brother[t]][t % 2]) {
            return t;
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    // 동생의 시간별 위치 계산
    brother[0] = K;
    for (int t = 1; t <= 500000; t++) {
        brother[t] = brother[t - 1] + t;
        if (brother[t] > 500000) break;
    }
    
    // 시작 위치에서 이미 만날 수 있는지 확인
    if (N == K) {
        cout << 0 << "\n";
        return 0;
    }
    
    int result = bfs();
    cout << result << "\n";
    
    return 0;
}