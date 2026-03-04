#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int h, w;
char building[100][100];
bool visited[100][100];
bool hasKey[26];
vector<pair<int, int>> doors[26];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q;
    int documents = 0;
    
    // 가장자리에서 시작 가능한 모든 위치를 큐에 넣음
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                if (building[i][j] != '*') {
                    char c = building[i][j];
                    
                    // 문인 경우
                    if (c >= 'A' && c <= 'Z') {
                        if (hasKey[c - 'A']) {
                            visited[i][j] = true;
                            q.push({i, j});
                        } else {
                            doors[c - 'A'].push_back({i, j});
                        }
                    } else {
                        visited[i][j] = true;
                        q.push({i, j});
                        
                        if (c == '$') documents++;
                        else if (c >= 'a' && c <= 'z') {
                            int key = c - 'a';
                            if (!hasKey[key]) {
                                hasKey[key] = true;
                                // 해당 열쇠로 열 수 있는 문들을 큐에 추가
                                for (auto door : doors[key]) {
                                    if (!visited[door.first][door.second]) {
                                        visited[door.first][door.second] = true;
                                        q.push(door);
                                    }
                                }
                                doors[key].clear();
                            }
                        }
                    }
                }
            }
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visited[nx][ny] || building[nx][ny] == '*') continue;
            
            char c = building[nx][ny];
            
            // 문인 경우
            if (c >= 'A' && c <= 'Z') {
                if (hasKey[c - 'A']) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else {
                    doors[c - 'A'].push_back({nx, ny});
                }
            } else {
                visited[nx][ny] = true;
                q.push({nx, ny});
                
                if (c == '$') {
                    documents++;
                } else if (c >= 'a' && c <= 'z') {
                    int key = c - 'a';
                    if (!hasKey[key]) {
                        hasKey[key] = true;
                        // 해당 열쇠로 열 수 있는 문들을 큐에 추가
                        for (auto door : doors[key]) {
                            if (!visited[door.first][door.second]) {
                                visited[door.first][door.second] = true;
                                q.push(door);
                            }
                        }
                        doors[key].clear();
                    }
                }
            }
        }
    }
    
    return documents;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> h >> w;
        
        memset(visited, false, sizeof(visited));
        memset(hasKey, false, sizeof(hasKey));
        for (int i = 0; i < 26; i++) {
            doors[i].clear();
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> building[i][j];
            }
        }
        
        string keys;
        cin >> keys;
        
        if (keys != "0") {
            for (char k : keys) {
                hasKey[k - 'a'] = true;
            }
        }
        
        int result = bfs();
        cout << result << "\n";
    }
    
    return 0;
}