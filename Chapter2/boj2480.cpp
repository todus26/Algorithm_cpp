// 2480번 주사위 세 개
#include <iostream>
using namespace std;

int main() {
    int a, b, c;  // 배열로 받을 수도 있음
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << 10000 + a * 1000 << endl;
    } else if (a == b || b == c || a == c) {
        if (a == b || a == c) {
            cout << 1000 + a * 100 << endl;
        } else {
            cout << 1000 + b * 100 << endl;
        }
    } else {
        cout << max(a, max(b, c)) * 100 << endl;
    }
}