// 2910번 - 빈도 정렬
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    map<int, int> frequency;  // 숫자별 빈도수
    map<int, int> firstIndex;  // 숫자가 처음 나온 인덱스
    vector<int> numbers;  // 입력된 숫자들 (중복 제거)
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        // 처음 나온 숫자인 경우
        if (frequency[num] == 0) {
            numbers.push_back(num);
            firstIndex[num] = i;
        }
        frequency[num]++;
    }
    
    // 정렬: 빈도수가 큰 것부터, 빈도수가 같으면 먼저 나온 것부터
    sort(numbers.begin(), numbers.end(), [&](int a, int b) {
        if (frequency[a] != frequency[b]) {
            return frequency[a] > frequency[b];
        }
        return firstIndex[a] < firstIndex[b];
    });
    
    // 출력
    for (int num : numbers) {
        for (int i = 0; i < frequency[num]; i++) {
            cout << num << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}