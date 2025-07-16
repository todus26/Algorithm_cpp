// 1919번 - 애너그램 만들기
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int count[26] = {0};

    for (char c : s1) {
        count[c - 'a']++;
    }
    for (char c : s2) {
        count[c - 'a']--;
    }

    int result = 0;
    for (int i = 0; i < 26; i++) {
        result += abs(count[i]);
    }

    cout << result << '\n';
    return 0;
}