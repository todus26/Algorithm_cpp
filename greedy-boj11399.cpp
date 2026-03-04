// 11399번 - ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    // 오름차순 정렬
    sort(P.begin(), P.end());
    
    int totalTime = 0;  // 모든 사람의 대기시간 합
    int waitTime = 0;   // 현재까지의 누적 대기시간
    
    for (int i = 0; i < N; i++) {
        waitTime += P[i];      // 현재 사람까지 포함한 시간
        totalTime += waitTime;  // 전체 대기시간에 추가
    }
    
    cout << totalTime << endl;
    
    return 0;
}