//4948번 - 베르트랑 공준
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int MAX = 246912;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int n;
    while (cin >> n && n != 0) {
        int count = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (is_prime[i]) {
                count++;
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}