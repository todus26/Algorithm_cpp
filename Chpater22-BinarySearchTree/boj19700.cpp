// 19700번 - 수업
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
        pair<int, int> a[500005];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n, greater<pair<int, int>>());

    multiset<int> s;

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(-a[i].second + 1);
        if (it == s.end()) s.insert(-1);
        else {
        int val = *it;

        s.erase(it);
        s.insert(val - 1);
        }
    }

    cout << s.size();
    return 0;
}