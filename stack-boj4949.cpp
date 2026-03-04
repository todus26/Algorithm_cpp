// 4949번 - 균형잡힌 세상
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    while (true) {
        getline(cin, str);
        if (str == ".") break;

        stack<char> s;
        bool is_balanced = true;

        for (char ch : str) {
            if (ch == '(' || ch == '[') {
                s.push(ch);
            } else if (ch == ')') {
                if (s.empty() || s.top() != '(') {
                    is_balanced = false;
                    break;
                }
                s.pop();
            } else if (ch == ']') {
                if (s.empty() || s.top() != '[') {
                    is_balanced = false;
                    break;
                }
                s.pop();
            }
        }

        if (is_balanced && s.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}