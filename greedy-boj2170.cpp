// 2170번 - 선 긋기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }
    
    // 시작점 기준으로 오름차순 정렬
    sort(lines.begin(), lines.end());
    
    // 첫 번째 선분으로 초기화
    int start = lines[0].first;
    int end = lines[0].second;
    long long totalLength = 0;
    
    for (int i = 1; i < N; i++) {
        int newStart = lines[i].first;
        int newEnd = lines[i].second;
        
        if (newStart <= end) {
            // 현재 선분과 겹치는 경우
            // 끝점을 더 큰 값으로 갱신
            end = max(end, newEnd);
        } else {
            // 현재 선분과 겹치지 않는 경우
            // 이전까지의 선분 길이를 더하고 새로운 선분으로 시작
            totalLength += (end - start);
            start = newStart;
            end = newEnd;
        }
    }
    
    // 마지막 선분의 길이 더하기
    totalLength += (end - start);
    
    cout << totalLength << endl;
    
    return 0;
}