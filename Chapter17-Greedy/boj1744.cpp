// 1744번 - 수 묶기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> positive;  // 양수 (2 이상)
    vector<int> negative;  // 음수와 0
    int ones = 0;          // 1의 개수
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if (num > 1) {
            positive.push_back(num);
        } else if (num == 1) {
            ones++;
        } else {
            // 0과 음수
            negative.push_back(num);
        }
    }
    
    // 양수는 내림차순 정렬 (큰 것끼리 묶기 위해)
    sort(positive.begin(), positive.end(), greater<int>());
    
    // 음수는 오름차순 정렬 (작은 것끼리 묶기 위해)
    sort(negative.begin(), negative.end());
    
    long long answer = 0;
    
    // 양수 처리: 큰 것부터 두 개씩 묶기
    for (int i = 0; i < positive.size(); i++) {
        if (i + 1 < positive.size()) {
            // 두 개를 묶을 수 있으면 묶기
            answer += (long long)positive[i] * positive[i + 1];
            i++;  // 두 개를 처리했으므로 i를 하나 더 증가
        } else {
            // 마지막 하나 남은 경우
            answer += positive[i];
        }
    }
    
    // 음수와 0 처리: 작은 것부터 두 개씩 묶기
    for (int i = 0; i < negative.size(); i++) {
        if (i + 1 < negative.size()) {
            // 두 개를 묶을 수 있으면 묶기
            // 음수 × 음수 = 양수, 음수 × 0 = 0
            answer += (long long)negative[i] * negative[i + 1];
            i++;
        } else {
            // 마지막 하나 남은 경우 (음수거나 0)
            answer += negative[i];
        }
    }
    
    // 1은 묶지 않고 그냥 더하기
    answer += ones;
    
    cout << answer << endl;
    
    return 0;
}