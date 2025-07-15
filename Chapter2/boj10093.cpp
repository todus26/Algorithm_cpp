// 10093번 숫자
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b) cout << 0 << endl;
    else {
        cout << b - a - 1 << endl;
        for (long long i = a + 1; i < b; i++) {
            cout << i << " ";
        }
    }
}