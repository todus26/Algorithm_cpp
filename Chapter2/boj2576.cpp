// 2576번 홀수
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int min = 100;
    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (num < min) {
                min = num;
            }
        }
    }
    if (sum == 0) cout << -1 << endl;
    else {
        cout << sum << endl;
        cout << min << endl;
    }
}