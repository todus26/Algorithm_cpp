// 14890번 - 경사로
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L;
vector<vector<int>> map;

bool canPass(vector<int>& road) {
    vector<bool> used(N, false);
    
    for (int i = 0; i < N - 1; i++) {
        if (road[i] == road[i + 1]) continue;
        
        // 높이 차이가 1보다 크면 불가능
        if (abs(road[i] - road[i + 1]) > 1) {
            return false;
        }
        
        // 오르막 (i < i+1)
        if (road[i] < road[i + 1]) {
            // i부터 왼쪽으로 L개가 같은 높이여야 함
            for (int j = 0; j < L; j++) {
                int idx = i - j;
                if (idx < 0 || used[idx] || road[idx] != road[i]) {
                    return false;
                }
                used[idx] = true;
            }
        }
        // 내리막 (i > i+1)
        else {
            // i+1부터 오른쪽으로 L개가 같은 높이여야 함
            for (int j = 0; j < L; j++) {
                int idx = i + 1 + j;
                if (idx >= N || used[idx] || road[idx] != road[i + 1]) {
                    return false;
                }
                used[idx] = true;
            }
        }
    }
    
    return true;
}

int main() {
    cin >> N >> L;
    map.resize(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    int answer = 0;
    
    // 가로 방향 검사
    for (int i = 0; i < N; i++) {
        vector<int> road(N);
        for (int j = 0; j < N; j++) {
            road[j] = map[i][j];
        }
        if (canPass(road)) {
            answer++;
        }
    }
    
    // 세로 방향 검사
    for (int j = 0; j < N; j++) {
        vector<int> road(N);
        for (int i = 0; i < N; i++) {
            road[i] = map[i][j];
        }
        if (canPass(road)) {
            answer++;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}