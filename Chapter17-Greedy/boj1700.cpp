// 1700번 - 멀티탭 스케줄링
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> schedule(K);
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }
    
    vector<int> multitap;
    int answer = 0;
    
    for (int i = 0; i < K; i++) {
        int device = schedule[i];
        
        // 1. 이미 꽂혀있는 경우
        bool already = false;
        for (int j = 0; j < multitap.size(); j++) {
            if (multitap[j] == device) {
                already = true;
                break;
            }
        }
        if (already) continue;
        
        // 2. 빈 자리가 있는 경우
        if (multitap.size() < N) {
            multitap.push_back(device);
            continue;
        }
        
        // 3. 빈 자리가 없는 경우 - 가장 나중에 사용될 것을 뽑기
        int removeIdx = -1;
        int lastUse = -1;
        
        for (int j = 0; j < N; j++) {
            int nextUse = K;  // 다시 사용되지 않으면 K
            
            // 현재 꽂혀있는 기기가 언제 다시 사용되는지 찾기
            for (int k = i + 1; k < K; k++) {
                if (multitap[j] == schedule[k]) {
                    nextUse = k;
                    break;
                }
            }
            
            // 가장 나중에 사용되는 기기 찾기
            if (nextUse > lastUse) {
                lastUse = nextUse;
                removeIdx = j;
            }
        }
        
        // 플러그 뽑고 새로운 기기 꽂기
        multitap[removeIdx] = device;
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}