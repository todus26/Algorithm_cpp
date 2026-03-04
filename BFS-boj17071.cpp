#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int visited[500001][2]; // [위치][홀수/짝수 시간]

int bfs() {
    queue<pair<int, int>> q; // {위치, 시간}
    q.push({N, 0});
    visited[N][0] = 1;
    
    int time = 0;
    int brotherPos = K;
    
    // 시작 위치에서 바로 만나는 경우
    if (N == brotherPos) return 0;
    
    while (brotherPos <= 500000) {
        // 현재 시간에 BFS 진행
        int qSize = q.size();
        
        for (int i = 0; i < qSize; i++) {
            int pos = q.front().first;
            int curTime = q.front().second;
            q.pop();
            
            // 세 가지 이동 방법
            int next[3] = {pos - 1, pos + 1, pos * 2};
            
            for (int j = 0; j < 3; j++) {
                int npos = next[j];
                int ntime = curTime + 1;
                
                if (npos < 0 || npos > 500000) continue;
                if (visited[npos][ntime % 2]) continue;
                
                visited[npos][ntime % 2] = 1;
                
                // 다음 시간의 동생 위치와 만나는지 확인
                if (npos == brotherPos + ntime) {
                    return ntime;
                }
                
                q.push({npos, ntime});
            }
        }
        
        time++;
        brotherPos += time;
        
        // 현재 동생 위치에 수빈이가 도달했는지 확인
        if (brotherPos <= 500000 && visited[brotherPos][time % 2]) {
            return time;
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    int result = bfs();
    cout << result << "\n";
    
    return 0;
}