// 14888번 - 연산자 끼워넣기
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> numbers;
vector<int> operators(4); // +, -, *, /
int maxResult = INT_MIN;
int minResult = INT_MAX;

void dfs(int idx, int result, int plus, int minus, int multi, int divide) {
    if (idx == n) {
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
        return;
    }
    
    if (plus > 0) {
        dfs(idx + 1, result + numbers[idx], plus - 1, minus, multi, divide);
    }
    if (minus > 0) {
        dfs(idx + 1, result - numbers[idx], plus, minus - 1, multi, divide);
    }
    if (multi > 0) {
        dfs(idx + 1, result * numbers[idx], plus, minus, multi - 1, divide);
    }
    if (divide > 0) {
        dfs(idx + 1, result / numbers[idx], plus, minus, multi, divide - 1);
    }
}

int main() {
    cin >> n;
    
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
    
    dfs(1, numbers[0], operators[0], operators[1], operators[2], operators[3]);
    
    cout << maxResult << '\n';
    cout << minResult << '\n';
    
    return 0;
}