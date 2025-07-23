// 9012번 - 괄호
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        stack<char> s;
        bool is_valid = true;

        for (char ch : str) {
            if (ch == '(') {
                s.push(ch);
            } else if (ch == ')') {
                if (s.empty() || s.top() != '(') {
                    is_valid = false;
                    break;
                }
                s.pop();
            }
        }

        if (is_valid && s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}