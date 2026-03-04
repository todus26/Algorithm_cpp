// 10799번 쇠막대기
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> s;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else {
            s.pop();
            if (str[i - 1] == '(') {
                cnt += s.size();
            } else {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}