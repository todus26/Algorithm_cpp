// 10773번 제로
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k;
    cin >> k;
    stack<int> s;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
    }
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
    return 0;
}