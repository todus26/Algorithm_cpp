// 11328번 Strfry
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1.length() != s2.length()) {
            cout << "Impossible\n";
            continue;
        }

        int count[26] = {0};

        for (char c : s1) {
            count[c - 'a']++;
        }
        for (char c : s2) {
            count[c - 'a']--;
        }

        bool isAnagram = true;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                isAnagram = false;
                break;
            }
        }

        cout << (isAnagram ? "Possible\n" : "Impossible\n");
    }

    return 0;
}