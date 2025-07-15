// 2493번 탑
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    stack<int> s;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] < v[i]) {
            result[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
    return 0;
}