// 10866번 - 덱

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    deque<int> dq;
    string command;
    int value;

    while (N--) {
        cin >> command;

        if (command == "push_front") {
            cin >> value;
            dq.push_front(value);
        } else if (command == "push_back") {
            cin >> value;
            dq.push_back(value);
        } else if (command == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "size") {
            cout << dq.size() << '\n';
        } else if (command == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (command == "front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}