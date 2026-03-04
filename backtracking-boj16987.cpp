// 16987 - 계란으로 계란치기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int idx, vector<int>& durability, vector<int>& weight) {
    int n = durability.size();
    
    // 모든 계란을 확인했으면 깨진 계란 수 반환
    if (idx == n) {
        int count = 0;
        for (int d : durability) {
            if (d <= 0) count++;
        }
        return count;
    }
    
    // 현재 든 계란이 이미 깨져있으면 다음 계란으로
    if (durability[idx] <= 0) {
        return dfs(idx + 1, durability, weight);
    }
    
    // 칠 수 있는 계란이 있는지 확인
    bool canHit = false;
    for (int i = 0; i < n; i++) {
        if (i != idx && durability[i] > 0) {
            canHit = true;
            break;
        }
    }
    
    // 칠 수 있는 계란이 없으면 다음 계란으로
    if (!canHit) {
        return dfs(idx + 1, durability, weight);
    }
    
    int maxBroken = 0;
    
    // 모든 다른 계란과 충돌 시뮬레이션
    for (int i = 0; i < n; i++) {
        if (i == idx || durability[i] <= 0) continue;
        
        // 계란 충돌: 각각의 내구도가 상대방의 무게만큼 감소
        durability[idx] -= weight[i];
        durability[i] -= weight[idx];
        
        maxBroken = max(maxBroken, dfs(idx + 1, durability, weight));
        
        // 원상복구
        durability[idx] += weight[i];
        durability[i] += weight[idx];
    }
    
    return maxBroken;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> durability(n);
    vector<int> weight(n);
    
    for (int i = 0; i < n; i++) {
        cin >> durability[i] >> weight[i];
    }
    
    cout << dfs(0, durability, weight) << "\n";
    
    return 0;
}