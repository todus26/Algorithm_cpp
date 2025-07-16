// 10808번 - 알파벳 개수
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int count[26] = {0};

    for (char c : s) {
        count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << count[i] << ' ';
    }
    
    cout << '\n';
    return 0;
}