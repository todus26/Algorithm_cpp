// 10828번 스택
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    stack<int> s;
    while (n--) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (command == "size") {
            cout << s.size() << '\n';
        } else if (command == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        } else if (command == "top") {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
    }
    
    return 0;
}