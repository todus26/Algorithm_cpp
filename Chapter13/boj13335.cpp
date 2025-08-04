// 13335번 - 트럭
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, w, L;
    cin >> n >> w >> L;

    vector<int> trucks(n);
    for (int i = 0; i < n; ++i) {
        cin >> trucks[i];
    }

    queue<pair<int, int>> bridge; // {트럭 무게, 나갈 시간}
    int time = 0, currentWeight = 0, truckIdx = 0;

    while (truckIdx < n || !bridge.empty()) {
        time++;

        // 다리에서 트럭이 나감
        if (!bridge.empty() && bridge.front().second == time) {
            currentWeight -= bridge.front().first;
            bridge.pop();
        }

        // 새로운 트럭이 다리에 올라갈 수 있는지 확인
        if (truckIdx < n && currentWeight + trucks[truckIdx] <= L) {
            currentWeight += trucks[truckIdx];
            bridge.push({trucks[truckIdx], time + w});
            truckIdx++;
        }
    }

    cout << time << endl;
    return 0;
}