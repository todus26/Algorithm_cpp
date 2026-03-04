//20166번 - 문자열 지옥에 빠진 호석
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M, K;
vector<string> grid;
vector<string> words;
unordered_map<string, int> count_map;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y, string current, int depth) {
    if (depth > 5) return;
    
    if (count_map.count(current)) {
        count_map[current]++;
    }
    
    for (int i = 0; i < 8; i++) {
        int nx = (x + dx[i] + N) % N;
        int ny = (y + dy[i] + M) % M;
        dfs(nx, ny, current + grid[nx][ny], depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    grid.resize(N);
    words.resize(K);
    
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    for (int i = 0; i < K; i++) {
        cin >> words[i];
        count_map[words[i]] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string start = "";
            start += grid[i][j];
            dfs(i, j, start, 1);
        }
    }
    
    for (int i = 0; i < K; i++) {
        cout << count_map[words[i]] << "\n";
    }
    
    return 0;
}