// 2504번 괄호의 값
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> s;
    int result = 0;
    int temp = 1;
    bool is_valid = true;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            temp *= 2;
            s.push(str[i]);
        } else if (str[i] == '[') {
            temp *= 3;
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                is_valid = false;
                break;
            }
            if (str[i - 1] == '(') {
                result += temp;
            }
            temp /= 2;
            s.pop();
        } else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                is_valid = false;
                break;
            }
            if (str[i - 1] == '[') {
                result += temp;
            }
            temp /= 3;
            s.pop();
        }
    }
    if (!is_valid || !s.empty()) {
        cout << 0 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}