#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

int bfs() {
    queue<int> q;
    q.push(S);
    visited[S] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == G) {
            return visited[G];
        }
        
        // 위로 U층 이동
        int up = current + U;
        if (up <= F && visited[up] == -1) {
            visited[up] = visited[current] + 1;
            q.push(up);
        }
        
        // 아래로 D층 이동
        int down = current - D;
        if (down >= 1 && visited[down] == -1) {
            visited[down] = visited[current] + 1;
            q.push(down);
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> F >> S >> G >> U >> D;
    
    memset(visited, -1, sizeof(visited));
    
    int result = bfs();
    
    if (result == -1) {
        cout << "use the stairs\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}