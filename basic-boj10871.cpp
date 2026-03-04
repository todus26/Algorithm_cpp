// 10871번 x보다 작은 수 
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < x) {
            cout << num << ' ';
        }
    }
    cout << '\n';
    return 0;
}