// 5648번 - 역원소 정렬
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long reverseNumber(long long num) {
    long long reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> numbers;
    
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        
        // 숫자를 뒤집기
        long long reversed = reverseNumber(num);
        numbers.push_back(reversed);
    }
    
    // 오름차순 정렬
    sort(numbers.begin(), numbers.end());
    
    // 출력
    for (long long num : numbers) {
        cout << num << '\n';
    }
    
    return 0;
}