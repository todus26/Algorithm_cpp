//18869번 - 멀티버스 Ⅱ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> universe(M, vector<int>(N));
    vector<vector<int>> compressed(M, vector<int>(N));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> universe[i][j];
        }
        
        vector<int> temp = universe[i];
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        for (int j = 0; j < N; j++) {
            compressed[i][j] = lower_bound(temp.begin(), temp.end(), universe[i][j]) - temp.begin();
        }
    }
    
    int answer = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            if (compressed[i] == compressed[j]) {
                answer++;
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}