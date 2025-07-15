// 3986번 좋은 단어
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<char> s;
        for (int j = 0; j < str.size(); j++) {
            if (s.empty()) {
                s.push(str[j]);
            } else {
                if (s.top() == str[j]) {
                    s.pop();
                } else {
                    s.push(str[j]);
                }
            }
        }
        if (s.empty()) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}