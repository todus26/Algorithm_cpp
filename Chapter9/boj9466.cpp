// 9466번 - 텀 프로젝트
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N;
int next_student[100001];
int visited[100001];  // 0: 미방문, 1: 현재 경로에서 방문중, 2: 완전히 처리됨
bool in_team[100001];
int team_count;

void dfs(int node) {
    visited[node] = 1;  // 현재 경로에서 방문중
    int next = next_student[node];
    
    if (visited[next] == 0) {
        // 아직 방문하지 않은 노드
        dfs(next);
    } else if (visited[next] == 1) {
        // 사이클 발견! next부터 현재 node까지가 사이클
        int curr = next;
        do {
            in_team[curr] = true;
            team_count++;
            curr = next_student[curr];
        } while (curr != next);
    }
    // visited[next] == 2인 경우는 이미 처리된 노드이므로 아무것도 하지 않음
    
    visited[node] = 2;  // 완전히 처리됨
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        // 초기화
        memset(visited, 0, sizeof(visited));
        memset(in_team, false, sizeof(in_team));
        team_count = 0;
        
        for (int i = 1; i <= N; i++) {
            cin >> next_student[i];
        }
        
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        
        cout << N - team_count << "\n";
    }
    
    return 0;
}