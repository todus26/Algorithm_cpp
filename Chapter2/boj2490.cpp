// 2490번 윷놀이
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b >> c >> d;

        int sum = a + b + c + d;
        if (sum == 0) {
            cout << "D" << endl;
        } else if (sum == 1) {
            cout << "C" << endl;
        } else if (sum == 2) {
            cout << "B" << endl;
        } else if (sum == 3) {
            cout << "A" << endl;
        } else {
            cout << "E" << endl;
        }
    }
}
