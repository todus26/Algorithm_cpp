#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char lake[1500][1500];
bool visited[1500][1500];
bool waterVisited[1500][1500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int, int> swan1, swan2;
queue<pair<int, int>> swanQ, nextSwanQ;
queue<pair<int, int>> waterQ, nextWaterQ;

bool moveSwan() {
    while (!swanQ.empty()) {
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            
            if (lake[nx][ny] == 'X') {
                nextSwanQ.push({nx, ny});
            } else {
                if (nx == swan2.first && ny == swan2.second) {
                    return true;
                }
                swanQ.push({nx, ny});
            }
        }
    }
    return false;
}

void meltIce() {
    while (!waterQ.empty()) {
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (waterVisited[nx][ny]) continue;
            
            if (lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                waterVisited[nx][ny] = true;
                nextWaterQ.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> R >> C;
    
    bool firstSwan = true;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> lake[i][j];
            
            if (lake[i][j] == 'L') {
                if (firstSwan) {
                    swan1 = {i, j};
                    firstSwan = false;
                } else {
                    swan2 = {i, j};
                }
                lake[i][j] = '.';
            }
            
            if (lake[i][j] == '.') {
                waterQ.push({i, j});
                waterVisited[i][j] = true;
            }
        }
    }
    
    swanQ.push(swan1);
    visited[swan1.first][swan1.second] = true;
    
    int days = 0;
    
    while (true) {
        if (moveSwan()) {
            cout << days << "\n";
            break;
        }
        
        meltIce();
        
        waterQ = nextWaterQ;
        swanQ = nextSwanQ;
        
        while (!nextWaterQ.empty()) nextWaterQ.pop();
        while (!nextSwanQ.empty()) nextSwanQ.pop();
        
        days++;
    }
    
    return 0;
}