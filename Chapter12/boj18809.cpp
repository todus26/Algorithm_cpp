#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, G, R;
int garden[50][50];
vector<pair<int, int>> lands;
int brute[10];
int maxFlower = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int bfs() {
    int cnt = 0;
    pair<int, int> state[50][50]; // {time, color}
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            state[i][j] = {-1, EMPTY};
        }
    }
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < lands.size(); i++) {
        if(brute[i] == GREEN || brute[i] == RED) {
            int x = lands[i].first;
            int y = lands[i].second;
            state[x][y] = {0, brute[i]};
            q.push({x, y});
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        int curTime = state[x][y].first;
        int curColor = state[x][y].second;
        
        if(state[x][y].second == FLOWER) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(garden[nx][ny] == 0) continue;
            
            if(state[nx][ny].second == EMPTY) {
                state[nx][ny] = {curTime + 1, curColor};
                q.push({nx, ny});
            }
            else if(state[nx][ny].second == RED) {
                if(curColor == GREEN && state[nx][ny].first == curTime + 1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
            else if(state[nx][ny].second == GREEN) {
                if(curColor == RED && state[nx][ny].first == curTime + 1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> G >> R;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> garden[i][j];
            if(garden[i][j] == 2) {
                lands.push_back({i, j});
            }
        }
    }
    
    int landSize = lands.size();
    
    // brute 배열 초기화: 뒤에서부터 G개는 GREEN, R개는 RED
    fill(brute + landSize - G - R, brute + landSize - R, GREEN);
    fill(brute + landSize - R, brute + landSize, RED);
    
    do {
        int result = bfs();
        maxFlower = max(maxFlower, result);
    } while(next_permutation(brute, brute + landSize));
    
    cout << maxFlower;
    
    return 0;
}