#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string initial;
    cin >> initial;
    
    // 두 개의 스택으로 커서 위치 관리
    // left: 커서 왼쪽 문자들
    // right: 커서 오른쪽 문자들 (뒤집혀서 저장)
    stack<char> left, right;
    
    // 초기 문자열을 왼쪽 스택에 저장 (커서는 맨 끝에 위치)
    for (char c : initial) {
        left.push(c);
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        
        if (command == 'L') {
            // 커서를 왼쪽으로 이동
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (command == 'D') {
            // 커서를 오른쪽으로 이동
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (command == 'B') {
            // 커서 왼쪽 문자 삭제
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (command == 'P') {
            // 커서 왼쪽에 문자 추가
            char ch;
            cin >> ch;
            left.push(ch);
        }
    }
    
    // 결과 출력
    // left 스택의 모든 원소를 right로 이동
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    
    // right 스택에서 하나씩 꺼내면서 출력
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    cout << '\n';
    
    return 0;
}