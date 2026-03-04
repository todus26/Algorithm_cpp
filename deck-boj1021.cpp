// 1021번 회전하는 큐
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> v(m);
    for (int i = 1; i <= n; i++) dq.push_back(i);
    for (int i = 0; i < m; i++) cin >> v[i];
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int idx = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == v[i]) {
                idx = j;
                break;
            }
        }
        if (idx < dq.size() - idx) {
            while (dq.front() != v[i]) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        } else {
            while (dq.front() != v[i]) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    cout << cnt << '\n';
    return 0;
}