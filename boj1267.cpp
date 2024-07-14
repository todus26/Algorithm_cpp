// 1267번 핸드폰 요금
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int y = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int call;
        cin >> call;
        y += (call / 30 + 1) * 10;
        m += (call / 60 + 1) * 15;
    }
    if (y < m) cout << "Y " << y << endl;
    else if (y > m) cout << "M " << m << endl;
    else cout << "Y M " << y << endl;
}