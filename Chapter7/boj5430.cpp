// 5430번 AC
#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        string p, x;
        int n;
        cin >> p >> n >> x;
        deque<int> dq;
        string temp = "";
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '[') continue;
            if (x[i] == ',' || x[i] == ']') {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            } else {
                temp += x[i];
            }
        }
        bool isReverse = false;
        bool isError = false;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                isReverse = !isReverse;
            } else {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                if (isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (isError) {
            cout << "error\n";
        } else {
            cout << '[';
            if (isReverse) {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0) cout << ',';
                }
            } else {
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1) cout << ',';
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}